// 1914D

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
#define frange(i, a, b) for (int i = (a); i < (b); ++i)
#define frev(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define print_vec(x) for (int i = 0; i < (int)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& a, vll& b, vll& c, int n) {
  vector<vll> dp(3, vector<ll>(3, n));
  a.pb(0);
  b.pb(0);
  c.pb(0);

//   dp[0][1]=1; dp[0][2]=2;
//   dp[1][1]=1; dp[1][2]=2;
//   dp[2][1]=1; dp[2][2]=2;

  frange(i, 0, n) {
    if (a[i] > a[dp[0][0]]) {
      dp[0][2] = dp[0][1];
      dp[0][1] = dp[0][0];
      dp[0][0] = i;
    } else if (a[i] > a[dp[0][1]]) {
      dp[0][2] = dp[0][1];
      dp[0][1] = i;
    } else if (a[i] > a[dp[0][2]]) dp[0][2] = i;

    if (b[i] > b[dp[1][0]]) {
      dp[1][2] = dp[1][1];
      dp[1][1] = dp[1][0];
      dp[1][0] = i;
    } else if (b[i] > b[dp[1][1]]) {
      dp[1][2] = dp[1][1];
      dp[1][1] = i;
    } else if (b[i] > b[dp[1][2]]) dp[1][2] = i;

    if (c[i] > c[dp[2][0]]) {
      dp[2][2] = dp[2][1];
      dp[2][1] = dp[2][0];
      dp[2][0] = i;
    } else if (c[i] > c[dp[2][1]]) {
      dp[2][2] = dp[2][1];
      dp[2][1] = i;
    } else if (c[i] > c[dp[2][2]]) dp[2][2] = i;
  }

//   print_vec(dp[0]);
//   print_vec(dp[1]);
//   print_vec(dp[2]);
  ll max_sum = 0;

  frange(i, 0, 3) {
    frange(j, 0, 3) {
      if (dp[1][j] == dp[0][i]) continue;
      frange(k, 0, 3) {
        if (dp[2][k] == dp[0][i] || dp[2][k] == dp[1][j]) continue;
        max_sum = max(max_sum, a[dp[0][i]] + b[dp[1][j]] + c[dp[2][k]]);
      }
    }
  }
  cout << max_sum << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll a(n);
    vll b(n);
    vll c(n);

    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];
    frange(i, 0, n) cin >> c[i];

    solve(a, b, c, n);
  }

  return 0;
}

