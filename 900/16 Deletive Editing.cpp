// 1666D

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

void solve(string s, string t) {
  int n = s.size();
  int m = t.size();

  int right_s = n-1;
  int right_t = m-1;
  map<char, int> s_passed;
  map<char, int> t_passed;

  while (right_s >= 0) {
    if (s[right_s] == t[right_t]) {
      for (auto t_ch : t.substr(0, right_t)) {
        if (s_passed[t_ch] > t_passed[t_ch]) {
          cout << "NO" << endl;
          return;
        }
      }

      s_passed[s[right_s]] += 1;
      t_passed[t[right_t]] += 1;

      right_t--;
      right_s--;
    }

    while (right_s >= 0 && s[right_s] != t[right_t]) {
      s_passed[s[right_s]] += 1;
      right_s--;
    }
  }

  if (right_t >= 0) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    string s, t;
    cin >> s >> t;

    solve(s, t);
  }

  return 0;
}

