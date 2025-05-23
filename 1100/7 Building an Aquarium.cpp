// 1873E

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
#define print_arr(x) for (int i = 0; i < (int)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& a, int n, ll x) {
  sort(all(a));
  ll a_sum = accumulate(all(a), 0);
  ll a_avg = a_sum / n;
  ll x_avg = x / n;
//  ll h = a_avg + x_avg;
  ll h = 1;

  ll left = 0;
  ll max_water = 0, max_h = 0;
  while (left < h) {
    ll cur_water = 0;
    frange(i, 0, n) {
      if (h <= a[i]) break;
      cur_water += h - a[i];
    }
    
    if (cur_water <= x) {
      if (max_water <= cur_water) {
        max_water = cur_water;
        max_h = h;
      }
      left = h;
      h *= 2;
    } else {
      h = left + (h - left) / 2;
    }
  }

  cout << max_h << endl;
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

