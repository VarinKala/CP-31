// 1931E

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

void solve() {
  ll n, m, sum = 0, right; cin >> n >> m;
  vll zeros;
  string s;
  vll a(n); frange(i, 0, n) {
    cin >> a[i];
    s = to_string(a[i]);
    right = s.size() - 1;
    sum += s.size();
    while (s[right] == '0') right--;
    if (s.size() - right - 1 > 0) zeros.pb(s.size() - right - 1);
  }

  sort(all(zeros), greater<ll>());
  for (int i = 0; i < zeros.size(); i += 2) sum -= zeros[i];

  if (sum <= m) cout << "Anna" << endl;
  else cout << "Sasha" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

