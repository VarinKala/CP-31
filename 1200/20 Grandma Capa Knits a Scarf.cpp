// 1582C

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
  ll n; cin >> n;
  string s; cin >> s;

  ll left = 0, right = n-1, ans = LLONG_MAX, cur = 0;
  for (auto ch : "abcdefghijklmnopqrstuvwxyz") {
    left = 0;
    right = n-1;
    cur = 0;
    while (left < right) {
      while (left < right && s[left] == s[right]) {
        left++;
        right--;
      } 

      if (left >= right) break;

      if (s[left] != ch && s[right] != ch) break;

      cur++;
      if (s[left] == ch) left++;
      else right--;
    }

    if (left >= right) ans = min(ans, cur);
  }

  cout << ((ans == LLONG_MAX) ? -1 : ans) << endl;
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

