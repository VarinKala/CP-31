// 1676G

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
  ll max_parent = 0;
  vll a(n+1); frange(i, 2, n+1) {
    cin >> a[i];
    max_parent = max(max_parent, a[i]);
  }
  string s; cin >> s;
  
  map<ll, pll> count;
  ll ans = 0;
  frev(idx, n+1, 1) {
    count[idx].F += (s[idx-1] == 'B');
    count[idx].S += (s[idx-1] == 'W');
    if (count[idx].F == count[idx].S) ans++;

    if (idx > 1) {
      count[a[idx]].F += count[idx].F;
      count[a[idx]].S += count[idx].S;
    }
  }

  cout << ans << endl;
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

