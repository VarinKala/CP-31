// 1807G2

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

void solve(vi& c, int n) {
  if (n == 1) {
    if (c[0] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
  }
  
  sort(all(c));

  ll sum = 1;
  frange(i, 1, n) {
    if (c[i] > sum) {
      cout << "NO" << endl;
      return;
    }

    sum += c[i];
  }

  cout << "YES" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi c(n);
    frange(i, 0, n) cin >> c[i];

    solve(c, n);
  }

  return 0;
}

