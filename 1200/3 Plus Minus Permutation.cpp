// 1872D

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

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(ll n, ll x, ll y) {
  ll x_count = 0, y_count = 0, common = 0;

//   for (ll i = 1; i <= n; i++) {
//     if (i % x == 0 && i % y == 0) common++;
//     else if (i % x == 0) x_count++;
//     else if (i % y == 0) y_count++;
//   }

  ll common_xy = lcm(x, y);
  common = n / common_xy;
  x_count = n / x - common;
  y_count = n / y - common;

  ll sum = 0;
  ll diff_x = n - x_count;
  if (diff_x % 2) sum -= diff_x * ((diff_x + 1) / 2);
  else sum -= (diff_x / 2) * (diff_x + 1);
  
  if (n % 2) sum += n * ((n + 1) / 2);
  else sum += (n / 2) * (n + 1);

  if (y_count % 2) sum -= y_count * ((y_count + 1) / 2);
  else sum -= (y_count / 2) * (y_count + 1);

  cout << sum << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, x, y;
    cin >> n >> x >> y;

    solve(n, x, y);
  }

  return 0;
}

