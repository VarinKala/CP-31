// 1671C

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

void solve(vll& a, ll n, ll x) {
  sort(all(a));

  vll cumulative(n);
  cumulative[0] = a[0];

  frange(i, 1, n) cumulative[i] = cumulative[i-1] + a[i];
  ll right = n-1, day = 0, count = 0;
  while (right >= 0) {
    while (right >= 0 && x - cumulative[right] - day*(right+1) < 0) right--;
    if (right == -1) break;
    ll jump = (x - cumulative[right] - day*(right+1)) / (right+1) + 1;
    day += jump;
    count += jump * (right+1);
  }

  cout << count << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, x;
    cin >> n >> x;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n, x);
  }

  return 0;
}

