// 1891B

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

void solve(vll& a, vi& x, int n, int q) {
  ll cur_factor;
  int prev = 31;

  frange(i, 0, q) {
    if (x[i] >= prev) continue;

    cur_factor = pow(2, x[i]);
    frange(j, 0, n) if (a[j] >= cur_factor && a[j] % cur_factor == 0) a[j] += pow(2, x[i]-1);
    prev = x[i];
  }

  print_vec(a);
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vll a(n);
    vi x(q);

    frange(i, 0, n) cin >> a[i];
    frange(i, 0, q) cin >> x[i];

    solve(a, x, n, q);
  }

  return 0;
}

