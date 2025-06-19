// 1447B

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
  ll n, m; cin >> n >> m;
  ll min_abs = 101;
  bool zeros = false;
  ll cur, sum = 0, neg_cnt = 0;
  frange(i, 0, n) {
    frange(j, 0, m) {
      cin >> cur;
      if (cur == 0) zeros = true;
      else if (cur < 0) neg_cnt++;

      sum += abs(cur);
      min_abs = min(min_abs, abs(cur));
    }
  }

  if (neg_cnt % 2 && !zeros) cout << sum - 2*min_abs << endl;
  else cout << sum << endl;
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

