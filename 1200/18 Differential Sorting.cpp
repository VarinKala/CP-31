// 1635C

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

void solve(vll& a, ll n) {
  bool clear = true;
  frange(i, 0, n-1) {
    if (a[i] > a[i+1]) {
      clear = false;
      break;
    }
  }

  if (clear) {
    cout << 0 << endl;
    return;
  }

  if (a[n-1] < 0 || a[n-2] > a[n-1]) {
    cout << -1 << endl;
    return;
  }

  vector<vll> ans;
  bool found = false;
  ll left = n-2, right= n-1;
  if (a[n-1] - a[n-2] > -1e18) found = true;

  frev(i, n-2, 0) {
    if (a[i] > a[i+1] && !found) {
      cout << -1 << endl;
      return;
    }

    if (!found && a[i] - a[i+1] > -1e18) {
      left = i;
      right = i + 1;
      found = true;
    }
    
    if (found && a[i] != a[left] - a[right]) {
      a[i] = a[left] - a[right];
      ans.pb({i+1, left+1, right+1});
    }
  }

  cout << ans.size() << endl;
  frange(i, 0, (ll)ans.size()) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

