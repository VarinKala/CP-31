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

void solve(vll& holidays, ll n, ll k, ll q) {
  vll intervals;
  ll cur_first = 0;

  frange(i, 0, n) {
    if (holidays[i] > q) {
      intervals.pb(i - cur_first);
      cur_first = i + 1;
    }
  }
  if (cur_first != n) intervals.pb(n - cur_first);

  ll n_intervals = intervals.size();
  
  ll comb = 0;
  frange(i, 0, n_intervals) {
    if (intervals[i] >= k) {
      ll factor = intervals[i] - k + 1;
      if (factor % 2) comb += ((factor+1) / 2) * factor;
      else comb += (factor / 2) * (factor + 1);
//       comb += (factor * (factor+1)) / 2;
    }
  }

  cout << comb << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, k, q;
    cin >> n >> k >> q;

    vll holidays(n);
    frange(i, 0, n) cin >> holidays[i];

    solve(holidays, n, k, q);
  }

  return 0;
}

