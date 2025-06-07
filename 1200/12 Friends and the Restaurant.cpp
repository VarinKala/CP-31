// 1729D

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

void solve(vll& x, vll& y, ll n) {
  vll diff(n);
  frange(i, 0, n) diff[i] = y[i] - x[i];

  sort(all(diff));

  auto it = lower_bound(all(diff), 0);
  if (it == diff.end()) {
    cout << 0 << endl;
    return;
  }

  ll right = it - diff.begin();
  ll left = right - 1;

  ll count = 0;
  while (right < n) {
    if (abs(diff[left]) <= diff[right]) {
      left--;
      right++;
      count++;
    } else if (right < n-1) {
      count++;
      right += 2;
    } else break;
  }

  cout << count << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vll x(n), y(n);
    frange(i, 0, n) cin >> x[i];
    frange(i, 0, n) cin >> y[i];

    solve(x, y, n);
  }

  return 0;
}

