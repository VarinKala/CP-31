// 1506C

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

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(string a, string b) {
  ll m = a.size(), n = b.size();
  vector<vll> dp(2, vll (n+1, 0));

  ll ans = 0;

  frange(i, 1, m + 1) {
    frange(j, 1, n + 1) {
      if (a[i-1] == b[j-1]) {
        ll val = 1 + dp[0][j-1];
        dp[1][j] = val;
        ans = max(ans, val);
      } else dp[1][j] = 0;
    }
    dp[0] = dp[1];
  }

  cout << m + n - 2*ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    string a, b;
    cin >> a >> b;

    solve(a, b);
  }

  return 0;
}

