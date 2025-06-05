// 1624B

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

void solve(ll a, ll b, ll c) {
  if ((2*b - a) % c == 0 && (2*b - a) / c > 0) {
    cout << "YES" << endl;
    return;
  }

  if ((2*b - c) % a == 0 && (2*b - c) / a > 0) {
    cout << "YES" << endl;
    return;
  }

  if (abs(c-a)%2 == 0 && (min(a, c) + abs(c-a)/2) % b == 0 && (min(a, c) + abs(c-a)/2) / b > 0) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;

    solve(a, b, c);
  }

  return 0;
}

