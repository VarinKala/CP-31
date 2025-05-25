// 1869B

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

void solve(int n, int k, int a, int b, vll& x, vll& y) {
  ll min_dist_a = LLONG_MAX, min_dist_b = LLONG_MAX;
  bool a_done = false, b_done = false;

  if (a <= k) {
    min_dist_a = 0;
    a_done = true;
  }
  if (b <= k) {
    min_dist_b = 0;
    b_done = true;
  }

  ll cur_dist = 0;
  if (k > 0 && (!a_done || !b_done)) {
    frange(i, 0, k) {
      if (!a_done) {
        cur_dist = abs(x[a-1] - x[i]) + abs(y[a-1] - y[i]);
        if (cur_dist == 0) {
          min_dist_a = 0;
          a_done = true;
        } else if (cur_dist < min_dist_a) min_dist_a = cur_dist;
      }

      if (!b_done) {
        cur_dist = abs(x[b-1] - x[i]) + abs(y[b-1] - y[i]);
        if (cur_dist == 0) {
          min_dist_b = 0;
          b_done = true;
        } else if (cur_dist < min_dist_b) min_dist_b = cur_dist;
      }
    }
  }

  ll direct_dist = abs(x[a-1] - x[b-1]);
  direct_dist += abs(y[a-1] - y[b-1]);

  ll dist_sum = min_dist_a + min_dist_b;

  if (dist_sum < 0) cout << direct_dist << endl;
  else cout << min(direct_dist, dist_sum) << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vll x(n);
    vll y(n);

    frange(i, 0, n) cin >> x[i] >> y[i];

    solve(n, k, a, b, x, y);
  }

  return 0;
}

