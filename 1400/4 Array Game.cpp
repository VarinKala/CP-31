// 1904C

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
using namespace std;

// Type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Macros
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define frange(i, a, b) for (ll i = (a); i < (b); ++i)
#define frev(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define print_vec(x) for (ll i = 0; i < (ll)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

const ll MOD = 1e9 + 7; // 998244353
const ll MAX = 1e5 + 5;

ll fact[MAX], inv_fact[MAX];
vector<bool> is_prime(MAX, true);

// Sieve of Eratosthenes
void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i < MAX; ++i) {
    if (is_prime[i]) {
      for (ll j = i * i; j < MAX; j += i) is_prime[j] = false;
    }
  }
}

// Modular exponentiation (a^b % mod)
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute_factorials() {
    fact[0] = inv_fact[0] = 1;
    for (ll i = 1; i < MAX; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2, MOD);  // Fermat’s Little Theorem
    for (ll i = MAX - 2; i >= 1; --i)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

// nCr = n! / (r! * (n - r)!)
ll nCr(ll n, ll r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n - r]) % MOD;
}

// nPr = n! / (n - r)!
ll nPr(ll n, ll r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (fact[n] * inv_fact[n - r]) % MOD;
}

void solve() {
  ll n, k; cin >> n >> k;
  vll a(n); frange(i, 0, n) cin >> a[i];

  if (k >= 3) {
    cout << 0 << endl;
    return;
  }

  sort(all(a));
  ll min_val = a[0];
  frange(i, 1, n) min_val = min(min_val, a[i] - a[i-1]);

  if (k == 1) {
    cout << min_val << endl;
    return;
  }

  frange(i, 0, n-1) {
    frange(j, i+1, n) {
      ll idx = lower_bound(all(a), a[j] - a[i]) - a.begin();
      if (idx < n) min_val = min(min_val, a[idx] - a[j] + a[i]);
      if (idx > 0) min_val = min(min_val, a[j] - a[i] - a[idx-1]);
    }
  }

  cout << min_val << endl;
}

int main() {
  fast_io;
  // sieve();
  // precompute_factorials();
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

