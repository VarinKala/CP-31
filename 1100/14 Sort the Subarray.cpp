// 1821B

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
#define frange(i, a, b) for (int i = (a); i < (b); ++i)
#define frev(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define print_vec(x) for (int i = 0; i < (int)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vi& a, vi& b, int n) {
  int left = 0, right = 1;
  int max_l = 0, max_r = 0;
  bool change = false;

  while (right < n) {
    if (b[right] < b[right-1]) {
      if (change) break;
      if (right - left > max_r - max_l) {
        max_l = left;
        max_r = right;
      }
      left = right;
    }

    if (a[right] != b[right]) change = true;

    right++;
  }

  if (change) cout << left+1 << " " << right << endl;
  else {
    if (right - left > max_r - max_l) cout << left+1 << " " << right << endl;
    else cout << max_l+1 << " " << max_r << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n);
    vi b(n);

    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];

    solve(a, b, n);
  }

  return 0;
}

