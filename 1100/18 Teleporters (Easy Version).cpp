// 1791G1

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

void solve(vll& a, ll n, ll c) {
  vll cumulative(n);
  frange(i, 0, n) cumulative[i] = i + 1 + a[i];

  sort(all(cumulative));
  if (c < cumulative[0]) {
    cout << 0 << endl;
    return;
  }

  frange(i, 1, n) {
    cumulative[i] += cumulative[i-1];
    if (c < cumulative[i]) {
      cout << i << endl;
      return;
    }
  }

  cout << n << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, c;
    cin >> n >> c;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n, c);
  }

  return 0;
}

