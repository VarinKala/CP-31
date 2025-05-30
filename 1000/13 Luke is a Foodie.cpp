// 1704B

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

void solve(vll& a, int n, ll x) {
  ll left = 0, right = 1e9;
  int changes = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] + x < left || a[i] - x > right) {
      changes++;
      left = a[i] - x;
      right = a[i] + x;
    } else {
      left = max(left, a[i] - x);
      right = min(right, a[i] + x);
    }
  }

  cout << changes << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    ll x;
    cin >> n >> x;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n, x);
  }

  return 0;
}

