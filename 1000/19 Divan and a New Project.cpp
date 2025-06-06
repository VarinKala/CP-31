// 1614B

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
#define print_vec(x) for (ll i = 0; i < (int)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& a, ll n) {
  vector<pair<ll, ll>> a2;
  frange(i, 0, n) a2.pb({a[i], i});

  sort(all(a2));
  map<pair<ll, ll>, ll> visit_to_idx;

  ll i = n-1, step = 1, mid = n / 2 + 1, T = 0, mid2 = n / 2 + 1;
  bool right = true;
  while(i >= 0) {
    if (right) {
      mid += step;
      T += a2[i].F * 2 * abs(mid - mid2);
      right = false;
    } else {
      mid -= step;
      T += a2[i].F * 2 * abs(mid - mid2);
      right = true;
    }
    visit_to_idx[a2[i]] = mid;

    step++;
    i--;
  }

  vll ans(n+1);
  ans[0] = mid2;
  frange(i, 0, n) {
    ans[a2[i].S + 1] = visit_to_idx[a2[i]];
  }

  cout << T << endl;
  print_vec(ans);
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

