// 1669H

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
  ll n, k; cin >> n >> k;
  vll bit_count(31);
  ll el;
  frange(i, 0, n) {
    cin >> el;
    frange(exp, 0, 31) {
      if ((1LL << exp) > el) break;
      bit_count[exp] += (el & (1LL<<exp)) ? 1 : 0;
    }
  }
  
  ll ans = 0, idx = 30;
  while (idx >= 0) {
    if (n - bit_count[idx] <= k) {
      k -= n - bit_count[idx];
      bit_count[idx] = n;
      ans |= 1 << idx;
    }
    idx--;
  }

  cout << ans << endl;
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

