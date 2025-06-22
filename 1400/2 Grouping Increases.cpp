// 1919C

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
  ll first = -1, second = -1;
  ll el, sum = 0;
  frange(i, 0, n) {
    cin >> el;
    if (first == -1) first = el;
    else if (second > -1) {
      if (first >= el && second >= el) {
        if (first <= second) first = el;
        else second = el;
      } else if (first >= el) first = el;
      else if (second >= el) second = el;
      else {
        if (first <= second) first = el;
        else second = el;
        sum++;
      }
    } else {
      if (first >= el) first = el;
      else second = el;
    }
  }

  cout << sum << endl;
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

