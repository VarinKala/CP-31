// 1744C

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

void solve(string s, char ch, int n) {
  s += s;
  int g_idx = s.find('g', n);
  int ry_max = 0;

  frev(i, n, 0) {
    if (s[i] == 'g') g_idx = i;
    if (s[i] == ch) ry_max = max(ry_max, g_idx - i);
  }

  cout << ry_max << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    char ch;
    string s;

    cin >> n >> s;
    ch = (s == "r") ? 'r' : (s == "g") ? 'g' : 'y';

    cin >> s;

    solve(s, ch, n);
  }

  return 0;
}

