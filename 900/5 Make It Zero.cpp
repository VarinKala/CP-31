// 1869A

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

void solve(vi& v, int n) {
  int zero_flag = 1;

  frange (i, 0, n) {
    if (v[i] != 0) {
      zero_flag = 0;
      break;
    }
  }

  if (zero_flag == 1) cout << 0 << endl;

  else {
    if (n % 2 == 0) {
      cout << 2 << endl;
      cout << 1 << " " << n << endl;
      cout << 1 << " " << n << endl;
    }
    else {
      cout << 4 << endl;
      cout << 1 << " " << n-1 << endl;
      cout << 1 << " " << n-1 << endl;
      cout << n-1 << " " << n << endl;
      cout << n-1 << " " << n << endl;
    }
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi v(n);
    frange (i, 0, n) cin >> v[i];

    solve(v, n);
  }

  return 0;
}

