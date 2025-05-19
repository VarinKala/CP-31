// 1913B

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

void solve(string s) {
  int n = (int) s.size();
  map<char, int> counter;
  counter['0'] = 0;
  counter['1'] = 0;

  frange (i, 0, n) counter[s[i]]++;

  frange (i, 0, n) {
    if (s[i] == '0') {
      counter['1']--;
      if (counter['1'] == -1) {
        cout << counter['0'] << endl;
        break;
      }
    }
    else {
      counter['0']--;
      if (counter['0'] == -1) {
        cout << counter['1'] << endl;
        break;
      }
    }
  }
  
  if (counter['0'] == 0 && counter['1'] == 0) cout << 0 << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    solve(s);
  }

  return 0;
}

