// 1808B

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

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vector<vll>& a, int n, int m) {
  ll sum = 0;
  vll cur_col;

  frange(j, 0, m) {
    cur_col = {};
    frange(i, 0, n) {
      cur_col.pb(a[i][j]);
    }

    sort(all(cur_col));
    frange(i, 0, n) {
      sum += cur_col[i] * (i - (n-i-1));
    }
  }

  cout << sum << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vll> a(n, vll(m));
    frange(i, 0, n) {
      frange(j, 0, m) cin >> a[i][j];
    }

    solve(a, n, m);
  }

  return 0;
}

