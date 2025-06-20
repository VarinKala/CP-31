// 1775B

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
  ll c(n);

  ll el, idx = 0;
  map<ll, ll> count;
  vll k(n);
  vector<vll> p(n);
  while (idx < n) {
    cin >> k[idx];
    frange(i, 0, k[idx]) {
      cin >> el;
      count[el]++;
      p[idx].pb(el);
    }
    idx++;
  }
  
  bool possible;
  frange(i, 0, n) {
    possible = true;
    for (auto bit : p[i]) {
      if (count[bit] == 1) {
        possible = false;
        break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
      return;
    }
  }
  
  cout << "NO" << endl;
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

