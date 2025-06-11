// 1594C

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
  ll n;
  char c;
  cin >> n >> c;
  cin.ignore();

  string s;
//  cin >> s;
  getline(cin, s);

  ll idx = -1;
  ll m = 0;
  frange(i, 0, n) {
    if (s[i] == c) {
      idx = i;
      m++;
    }
  }

  if (m == n) {
    cout << 0 << endl;
    return;
  }

  if (idx >= n/2) {
    cout << 1 << endl;
    cout << idx+1 << endl;
  } else {
    cout << 2 << endl;
    cout << n-1 << " " << n << endl;
  }
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

