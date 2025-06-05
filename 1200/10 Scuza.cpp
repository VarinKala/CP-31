// 1742E

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

void solve(vll& a, vll& k, ll n, ll q) {
  vll max_a(n);
  max_a[0] = a[0];
  vll cumulative(n);
  cumulative[0] = a[0];

  frange(i, 1, n) {
    max_a[i] = max(max_a[i-1], a[i]);
    cumulative[i] = cumulative[i-1] + a[i];
  }

  frange(j, 0, q) {
    if (k[j] < max_a[0]) {
      cout << 0 << " ";
      continue;
    }

    auto it = upper_bound(all(max_a), k[j]);
    if (it == max_a.end()) cout << cumulative[n-1] << " ";
    else {
      ll idx = it - max_a.begin();
      cout << cumulative[idx-1] << " ";
    }
  }

  cout << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, q;
    cin >> n >> q;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    vll k(q);
    frange(i, 0, q) cin >> k[i];

    solve(a, k, n, q);
  }

  return 0;
}

