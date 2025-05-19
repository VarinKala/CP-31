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

void solve(string s, ll n) {
  vll left_unique(n);
  vll right_unique(n);
  map<char, int> left_m, right_m;

  left_unique[0] = 1;
  right_unique[n-1] = 1;
  left_m[s[0]] = 1;
  right_m[s[n-1]] = 1;

  frange(i, 1, n) {
    if (left_m.count(s[i])) left_unique[i] = left_unique[i-1];
    else {
      left_unique[i] = left_unique[i-1] + 1;
      left_m[s[i]] = 1;
    }
  }

  frev(i, n-1, 0) {
    if (right_m.count(s[i])) right_unique[i] = right_unique[i+1];
    else {
      right_unique[i] = right_unique[i+1] + 1;
      right_m[s[i]] = 1;
    }
  }

  ll ans = 0;
  frange(i, 0, n-1) ans = max(ans, left_unique[i] + right_unique[i+1]);

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    solve(s, n);
  }

  return 0;
}

