// 1607B

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

void solve(ll x0, ll n) {
  ll div = (n / 4) * 4 + 1, mod = n % 4;

  if (mod == 1) {
    if (x0 % 2) x0 += div;
    else x0 -= div;
  } else if (mod == 2) {
    if (x0 % 2) x0 -= 1;
    else x0 += 1;
  } else if (mod == 3) {
    if (x0 % 2) x0 -= (div + 3);
    else x0 += div + 3;
  }

  cout << x0 << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll x0, n;
    cin >> x0 >> n;

    solve(x0, n);
  }

  return 0;
}

