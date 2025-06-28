// 1830A

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
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
  vector<vll> adj(n, vll());
  map<pll, ll> edge_idx;
  vll cycle(n-1, -1);
  ll u, v;
  stack<ll> s;
  vll parent(n, -1);
  parent[0] = 0;
  frange(i, 0, n-1) {
    cin >> u >> v;
    u -= 1;
    v -= 1;
    adj[u].pb(v);
    adj[v].pb(u);
    edge_idx[{min(u, v), max(u, v)}] = i;
    if (min(u, v) == 0) {
      cycle[i] = 1;
      s.push(max(u, v));
      parent[max(u, v)] = 0;
    }
  }

  ll cur, max_cycle = 1, cur_idx, prev_idx;
  while (!s.empty()) {
    cur = s.top();
    s.pop();

    for (auto vertex : adj[cur]) {
      if (parent[vertex] > -1) continue;
      parent[vertex] = cur;
      s.push(vertex);
      cur_idx = edge_idx[{min(cur, vertex), max(cur, vertex)}];
      prev_idx = edge_idx[{min(cur, parent[cur]), max(cur, parent[cur])}];
      cycle[cur_idx] = cycle[prev_idx];
      if (cur_idx < prev_idx) cycle[cur_idx] += 1;
      max_cycle = max(max_cycle, cycle[cur_idx]);
    }
  }

  cout << max_cycle << endl;
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

