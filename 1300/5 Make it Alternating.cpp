// 1879C

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
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define frange(i, a, b) for (ll i = (a); i < (b); ++i)
#define frev(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define print_vec(x) for (ll i = 0; i < (ll)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second
#define MOD 998244353

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve() {
  string s; cin >> s;

  ll n = s.size();
  ll rep = 0, count = 1;
  ll ans = 1;

  frange(i, 1, n) {
    if (s[i] != s[i-1]) {
      count++;
      ans = (ans*(i-rep)) % MOD;
      rep = i;
    }
  }
  ans = (ans*(n-rep)) % MOD;
  frange(i, 2, n-count+1) ans = (ans*i) % MOD;

  cout << n - count << " " << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

