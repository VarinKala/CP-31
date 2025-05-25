// 1842B

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

void solve(vll& a, vll& b, vll& c, int n, ll x) {
  ll check = 0;
  int a_idx = 0, b_idx = 0, c_idx = 0;
  bool update = false;

  while (a_idx < n || b_idx < n || c_idx < n) {
    update = false;
    if (a_idx < n && (a[a_idx] | x) == x) {
      check |= a[a_idx++];
      update = true;
    }
    if (b_idx < n && (b[b_idx] | x) == x) {
      check |= b[b_idx++];
      update = true;
    }
    if (c_idx < n && (c[c_idx] | x) == x) {
      check |= c[c_idx++];
      update = true;
    }

    if (!update || check == x) break;
  }

  if (check == x) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    ll x;
    cin >> n >> x;

    vll a(n);
    vll b(n);
    vll c(n);
    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];
    frange(i, 0, n) cin >> c[i];

    solve(a, b, c, n, x);
  }

  return 0;
}

