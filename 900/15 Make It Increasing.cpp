// 1675B

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

void solve(vll& a, int n) {
  if (n > 1 && a[n-1] == 0) {
    cout << -1 << endl;
    return;
  }

  int ops = 0;

  frev(i, n-1, 0) {
    while (a[i+1] <= a[i]) {
      a[i] /= 2;
      ops++;
      if (a[i] == 0) break;
    }

    if (a[i] == 0 && a[i+1] == 0) {
      cout << -1 << endl;
      return;
    }
  }

  cout << ops << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

