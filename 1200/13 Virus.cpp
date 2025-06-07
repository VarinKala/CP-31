// 1704C

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

void solve(vll& a, ll n, ll m) {
  sort(all(a));

  vll diff(m);
  diff[0] = a[0] - 1 + n - a[m-1];
  frange(i, 1, m) diff[i] = a[i] - a[i-1] - 1;

  sort(all(diff));

  ll safe = 0;
  ll right = m-1;
  ll turns = 0;
  while (right >= 0) {
    if (diff[right] - 2*turns > 2) {
      safe += diff[right] - 2*turns - 1;
      turns += 2;
    } else if (diff[right] - 2*turns <= 0) break;
    else {
      safe += 1;
      turns++;
    }

    right--;
  }

  cout << n - safe << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, m;
    cin >> n >> m;

    vll a(m);
    frange(i, 0, m) cin >> a[i];

    solve(a, n, m);
  }

  return 0;
}

