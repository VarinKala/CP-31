// 1536B

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

  string s2 = "";

  vector<string> chars;
  chars = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  vector<string> chars2(chars.begin()+1, chars.end());

  for (auto ch1 : chars) {
    s2 += ch1;

    for (auto ch2 : chars) {
      if (ch1 != "" && ch2 == "") continue;
      s2 += ch2;

      for (auto ch3 : chars2) {
        s2 += ch3;
        if (s.find(s2) == string::npos) {
          cout << s2 << endl;
          return;
        }
        s2.pop_back();
      }
      if (ch2 != "") s2.pop_back();
    }
    if (ch1 != "") s2.pop_back();
  }

  cout << -1 << endl;
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

