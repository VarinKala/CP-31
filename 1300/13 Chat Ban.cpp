// 1612C

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
  ll k, x; cin >> k >> x;

  if (k*k <= x) {
    cout << 2*k-1 << endl;
    return;
  }

  ll half = (k%2) ? ((k+1)/2)*k : (k/2) * (k+1);
  if (half >= x) {
    ll n = ceill((sqrtl((long double)(1 + 8*x)) - 1) / 2);
    cout << n << endl;
  } else {
    x -= half;
    ll n = ceill((2*k - 1 - sqrtl((long double)(4*k*k - 4*k + 1 - 8*x))) / 2);
    cout << k + n << endl;
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

