// 1881D

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

vll calcSmallestFactor(ll n) {
  vll primes;
  vll smallest_factor(n+1, 0);

  smallest_factor[0] = 1;
  smallest_factor[1] = 1;

  frange(i, 2, n+1) {
    if (smallest_factor[i] == 0) {
      primes.pb(i);
      smallest_factor[i] = i;
    }

    for (ll j = 0; j < (ll)primes.size() && i*primes[j] < n && primes[j] <= smallest_factor[i]; j++) {
      smallest_factor[i*primes[j]] = primes[j];
    }
  }

  return smallest_factor;
}

void solve(vll& smallest_factor) {
  ll n; cin >> n;
  vll a(n); frange(i, 0, n) cin >> a[i];

  map<ll, ll> count;

  frange(i, 0, n) {
    while (a[i] > 1) {
      count[smallest_factor[a[i]]]++;
      a[i] /= smallest_factor[a[i]];
    }
  }

  for (auto [k, v] : count) {
    if (v % n) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;
  vll smallest_factor = calcSmallestFactor(1000001);

  while (t--) {
    solve(smallest_factor);
  }

  return 0;
}

