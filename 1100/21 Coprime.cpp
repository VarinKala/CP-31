// 1742D

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
  vector<vll> coprimes;
  coprimes.pb({});
  frange(i, 1, 1001) {
    coprimes.pb({});
    frange(j, 1, 1001) {
      if (gcd(i, j) == 1) coprimes[i].pb(j);
    }
  }

  vll loc(1001, -1);
  ll ans = -1;
  frev(i, n, 0) {
    if (loc[a[i]] == -1) {
      loc[a[i]] = i;
      ll m = coprimes[a[i]].size();
      frange(j, 0, m) {
        if (loc[coprimes[a[i]][j]] > -1) ans = max(ans, loc[coprimes[a[i]][j]] + i + 2);
      }
    }
  }
  
  cout << ans << endl;
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

