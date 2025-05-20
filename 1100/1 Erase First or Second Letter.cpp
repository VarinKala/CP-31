// 1917B

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
  vll distinct(n);
  set<char> unique;
  unique.insert(s[0]);
  distinct[0] = 1;
  ll total = 1;

  frange(i, 1, n) {
    if (!unique.count(s[i])) {
      unique.insert(s[i]);
      distinct[i] = distinct[i-1] + 1;
    } else distinct[i] = distinct[i-1];
    total += distinct[i];
  }

  cout << total << endl;
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

