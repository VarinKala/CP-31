// 1915E

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
  vll a(n); frange(i, 0, n) cin >> a[i];

  if (n == 1) {
    cout << "NO" << endl;
    return;
  }

  for (ll i = 1; i < n; i += 2) a[i] *= -1;

  map<ll, ll> pos;
  pos[0] = 1;
  ll sum = 0;
  frange(i, 1, n+1) {
    sum += a[i-1];
    if (pos[sum] != 0) {
      cout << "YES" << endl;
      return;
    }
    pos[sum] = i+1;
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

