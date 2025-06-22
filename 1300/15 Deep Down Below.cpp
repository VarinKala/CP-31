// 1561C

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
  vll k(n);
  vector<vll> a;
  ll el;
  frange(i, 0, n) {
    cin >> k[i];
    a.pb({});
    frange(j, 0, k[i]) {
      cin >> el;
      a[i].pb(el);
    }
  }

  vector<pll> required_energy(n);
  ll req_energy;
  frange(i, 0, n) {
    req_energy = a[i][k[i]-1]+1;
    frev(idx, k[i]-1, 0) {
      req_energy--;
      req_energy = max(req_energy, a[i][idx]+1);
    }
    required_energy[i] = {req_energy, k[i]};
  }

  sort(all(required_energy));
  ll ans = required_energy[n-1].F;
  frev(idx, n-1, 0) ans = max(required_energy[idx].F, ans - required_energy[idx].S);
  
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

