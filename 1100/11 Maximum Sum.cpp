// 1832B

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

void solve(vll& a, int n, int k) {
  sort(all(a));

  vll cumulative(n+1);
  cumulative[0] = a[0];

  frange(i, 0, n) cumulative[i+1] = cumulative[i] + a[i];

  ll max_sum = 0;
  frange(i, 0, k+1) max_sum = max(max_sum, cumulative[n - k + i] - cumulative[2 * i]);    

  cout << max_sum << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n, k);
  }

  return 0;
}

