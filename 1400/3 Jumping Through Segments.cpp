// 1907D

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

void solve() {
  ll n; cin >> n;
  ll max_b = -1;
  vll a(n+1), b(n+1); frange(i, 1, n+1) {
    cin >> a[i] >> b[i];
    max_b = max(max_b, b[i]);
  }

  ll left = 0, right = max_b;
  ll res = max_b, cur_left, cur_right, l, r;
  bool check;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    check = true;
    cur_left = 0;
    cur_right = 0;
    frange(i, 1, n+1) {
      l = cur_left - mid;
      r = cur_right + mid;

      if (b[i] < l || a[i] > r) {
        check = false;
        break;
      }

      cur_left = max(l, a[i]);
      cur_right = min(r, b[i]);
    }

    if (check) {
      right = mid - 1;
      res = mid;
    } else left = mid + 1;
  }

  cout << res << endl;
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

