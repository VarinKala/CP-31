// 1837D

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <stack>
using namespace std;

// Type definitions
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

// Macros
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define frange(i, a, b) for (ll i = (a); i < (b); ++i)
#define frev(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define print_vec(x) for (ll i = 0; i < (ll)(x).size(); i++) cout << (x)[i] << " "; cout << endl
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
  ll n; cin >> n;
  string s; cin >> s;

  stack<ll> open, close;
  vll color(n, 2);
  frange(i, 0, n) {
    if (s[i] == ')' && !open.empty()) {
      color[open.top()] = 1;
      color[i] = 1;
      open.pop();
    } else if (s[i] == ')') close.push(i);
    else open.push(i);
  }

  if (open.size() != close.size()) {
    cout << -1 << endl;
    return;
  }

  if (open.size() == 0 || (n % 2 == 0 && open.size() == n/2)) {
    cout << 1 << endl;
    frange(i, 0, n) cout << "1 ";
    cout << endl;
    return;
  }

  while (!open.empty()) open.pop();
  while (!close.empty()) close.pop();

  bool possible = true;
  frev(i, n, 0) {
    if (s[i] == '(') open.push(i);
    else if (s[i] == ')' and !open.empty()) open.pop();
    else {
      possible = false;
      break;
    }
  }

  if (possible) {
    cout << 1 << endl;
    frange(i, 0, n) cout << "1 ";
    cout << endl;
    return;
  }

  cout << 2 << endl;
  frange(i, 0, n) cout << color[i] << " ";
  cout << endl;
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

