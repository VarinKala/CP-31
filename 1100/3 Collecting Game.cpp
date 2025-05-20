// 1904B

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
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
#define pb push_back
#define F first
#define S second

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& a, int n) {
  vector<pll> pairs;
  frange(i, 0, n) pairs.pb({a[i], i});

  sort(all(pairs));

  vll cumulative_a(n);
  cumulative_a[0] = pairs[0].F;

  frange(i, 1, n) cumulative_a[i] = pairs[i].F + cumulative_a[i-1];

  vector<ll> ans(n);
  frange(i, 0, n) {
    ll j = i;
    ll found = i;

    while (j < n) {
      pll temp = {cumulative_a[j] + 1, LLONG_MIN};
      ll idx = lower_bound(all(pairs), temp) - pairs.begin();
      idx--;
      
      if (idx == j) break;

      found += idx-j;
      j = idx;
    }
    ans[pairs[i].S] = found;
  }

  frange(i, 0, n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

