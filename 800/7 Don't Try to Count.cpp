// 1881A

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

bool check(string s, string x) {
  if (x.size() < s.size()) return false;

  frange(i, 0, (int)(x.size() - s.size() + 1)) {
    if (x.substr(i, s.size()) == s) return true;
  }

  return false;
}

void solve(string x, string s, ll n, ll m) {
  vector<string> possible_x;
  possible_x.pb(x);
  frange(i, 0, 5) possible_x.pb(possible_x.back() + possible_x.back());

  ll ans = -1;
  
  frange(i, 0, 6) {
    if (check(s, possible_x[i])) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, m;
    cin >> n >> m;

    string s, x;
    cin >> s;
    cin >> x;

    solve(s, x, n, m);
  }

  return 0;
}

