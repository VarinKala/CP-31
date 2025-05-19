// 1859B

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

void solve(vector<vll>& v, vll& lens, ll n) {
  vll min_vals(n);
  vll min_2_vals(n);
  int min_2_idx = 0;
  ll min_val = LLONG_MAX;

  frange (i, 0, n) {
    min_vals[i] = v[i][0];
    min_2_vals[i] = v[i][1];

    if (min_2_vals[min_2_idx] > min_2_vals[i]) min_2_idx = i;
    min_val = min(min_val, min_vals[i]);
  }

  ll ans = 0;
  frange (i, 0, n) {
    if (i == min_2_idx) {
      ans += min_val;
    }
    else {
      ans += min_2_vals[i];
    }
  }

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    
    vector<vll> v(n);
    vll lens(n);

    frange (i, 0, n) {
      ll m;
      cin >> m;

      vll a(m);
      frange (j, 0, m) cin >> a[j];

      sort(all(a));
      v[i] = a;
      lens[i] = m;
    }

    solve(v, lens, n);
  }

  return 0;
}

