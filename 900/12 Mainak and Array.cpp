// 1726A

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

void solve(vi& a, int n) {
  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  int ans = a[n-1] - a[0], cur_diff = 0;
  int min_el = a[0], max_el = a[0];

  frange(i, 1, n) {
    cur_diff = a[i-1] - a[i];
    ans = max(ans, cur_diff);

    min_el = min(min_el, a[i]);
    max_el = max(max_el, a[i]);
  }

  ans = max(ans, max_el - a[0]);
  ans = max(ans, a[n-1] - min_el);

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

