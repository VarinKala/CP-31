// 1827A

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

void solve(vll& a, vll& b, int n) {
  ll MOD = 1e9+7;
  sort(all(a));
  sort(all(b), greater<int>());

  bool possible = true;
  ll perm = 1;
  int cur_count = 0;
  frange(i, 0, n) {
    auto it = upper_bound(all(a), b[i]);
    cur_count = a.end() - it - i;
    if (cur_count <= 0) {
      possible = false;
      break;
    }

    perm = (perm * cur_count) % MOD;
  }

  if (!possible) cout << 0 << endl;
  else cout << perm << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll a(n);
    vll b(n);

    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];

    solve(a, b, n);
  }

  return 0;
}

