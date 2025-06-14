// 1485A

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
  ll a, b; cin >> a >> b;

  if (a == 0) {
    cout << 0 << endl;
    return;
  }
  if (b > a) {
    cout << 1 << endl;
    return;
  }

  ll offset = 0;
  if (b == 1) {
    offset = 1;
    b = 2;
  }

  ll ans = INT_MAX, a2 = 0, b2 = 0, ops = 0;
  frange(i, 0, 32) {
    ops = i;
    b2 = b + i;
    a2 = a;
    while (a2 > 0) {
      ops++;
      a2 /= b2;
    }
    ans = min(ans, ops);
  }

  cout << offset + ans << endl;
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

