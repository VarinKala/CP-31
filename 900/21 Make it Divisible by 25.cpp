// 1593B

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

void solve(ll n) {
  ll rem = -1, i = 0;
  bool found0 = false, found5 = false;
  while (n > 0) {
    i++;
    rem = n % 10;
    if (!found0 && rem == 0) {
      found0 = true;
    } else if (!found5 && rem == 5) {
      found5 = true;
      if (found0) {
        cout << i - 2 << endl;
        return;
      }
    } else if (found0 && (rem == 0 || rem == 5)) {
      cout << i - 2 << endl;
      return;
    } else if (found5 && (rem == 2 || rem == 7)) {
      cout << i - 2 << endl;
      return;
    }
    n /= 10;
  }
  cout << -1 << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    solve(n);
  }

  return 0;
}

