// 1338A

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <climits>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Type definitions
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vll DSU_parent(MAX, -1);
ll DSU_size[MAX];

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

void DSU_make(ll v) {
  DSU_parent[v] = v;
  DSU_size[v] = 1;
}

ll DSU_find(ll v) {
  if (v == DSU_parent[v]) return v;
  return DSU_parent[v] = DSU_find(DSU_parent[v]);
}

void DSU_union(ll a, ll b) {
  a = DSU_find(a);
  b = DSU_find(b);
  if (a != b) {
    if (DSU_size[a] < DSU_size[b]) swap(a, b);
    DSU_parent[b] = a;
    DSU_size[a] += DSU_size[b];
  }
}

void solve() {
  ll n; cin >> n;
  vll a(n); 
  ll max_element = -1e9-1, ans = 0;
  frange(i, 0, n) {
    cin >> a[i];
    if (a[i] < max_element) ans = max(ans, max_element - a[i]);
    else max_element = max(max_element, a[i]);
  }

  if (ans < 2) cout << ans << endl;
  else cout << floorl(log2(ans)) + 1 << endl;
}

int main() {
  fast_io;
  // sieve();
  // precompute_factorials();
  ll t;
  cin >> t; //  t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

