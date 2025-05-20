// 1914C

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
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
#define pb push_back
#define F first
#define S second

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vi& a, vi& b, int n, int k) {
  int maxi = 0, sum = 0, ans = 0;

  frange(i, 0, min(n, k)) {
    sum += a[i];
    maxi = max(maxi, b[i]);
    ans = max(ans, sum + (k-i-1) * maxi);
  }

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vi a(n), b(n);
    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];

    solve(a, b, n, k);
  }

  return 0;
}

