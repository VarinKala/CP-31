// 1883C

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

void solve(vi& v, int n, int k) {
  if (k == 4) {
    int ops = 4;
    int div2 = 0;
    int ndiv2 = 0;

    frange (i, 0, n) {
      if (v[i] % 2 == 0) div2++;
      else ndiv2++;

      if (div2 >= 2) {
        ops = 0;
        break;
      }

      int mod_val = (k - (v[i] % k)) % k;
      ops = min(ops, mod_val);
      if (ops == 0) break;
    }

    cout << min(ops, 2 - div2) << endl;
  }

  else {
    int ops = k;
  
    frange (i, 0, n) {
      int mod_val = (k - (v[i] % k)) % k;
      ops = min(ops, mod_val);
      if (ops == 0) break;
    }
  
    cout << ops << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vi v(n);
    frange (i, 0, n) cin >> v[i];

    solve(v, n, k);
  }

  return 0;
}

