// 1848B

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

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vi& c, int n, int k) {
  vi jumps(k, 0);
  vi jumps2(k, 0);
  vi prev(k, -1);
  
  frange(i, 0, n) {
    if (i - prev[c[i]-1] - 1 > jumps[c[i]-1]) {
      jumps2[c[i]-1] = jumps[c[i]-1];
      jumps[c[i]-1] = i - prev[c[i]-1] - 1;
    } else if (i - prev[c[i]-1] - 1 > jumps2[c[i]-1]) jumps2[c[i]-1] = i - prev[c[i]-1] - 1;
    prev[c[i]-1] = i;
  }

  frange(i, 0, k) {
    if (prev[i] != -1) {
      if (n - prev[i] - 1> jumps[i]) {
        jumps2[i] = jumps[i];
        jumps[i] = n - prev[i] - 1;
      } else if (n - prev[i] - 1 > jumps2[i]) jumps2[i] = n - prev[i] - 1;
    }
  }

  int min_jumps = n;
  int cur_max_jump;
  frange(i, 0, k) {
    if (prev[i] != -1) {
      cur_max_jump = max(max(0, jumps[i] / 2), jumps2[i]);
      min_jumps = min(min_jumps, cur_max_jump);
    }
  }

  cout << min_jumps << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vi c(n);
    frange(i, 0, n) cin >> c[i];

    solve(c, n, k);
  }

  return 0;
}

