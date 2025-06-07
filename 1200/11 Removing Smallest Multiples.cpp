// 1734C

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

void solve(string s, ll n) {
  ll sum = 0, idx = 0;
  string done = "";
  string final = "";
  ll count = 0;
  frange(i, 0, n) {
    if (s[i] == '0') count++;
    done += '0';
    final += '1';
  }

  frange(i, 0, n) {
    idx = i;
    while (idx < n && done[idx] == '1') idx += i + 1;

    while (idx < n && s[idx] == '0') {
      if (done[idx] == '0') {
        sum += i + 1;
        done[idx] = '1';
        count--;
      }
      idx += i + 1;
      if (count == 0) break;
    }
    if (count == 0) break;
  }

  cout << sum << endl;
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

