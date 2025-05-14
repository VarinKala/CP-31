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

void solve(string s) {
  int gap_flag = 0, count_gaps = 0;
  int prev_gaps = 0;

  frange (i, 0, (int)s.size()) {
    if (s[i] == '#') prev_gaps = 0;
    else {
      prev_gaps++;
      count_gaps++;

      if (prev_gaps == 3) {
        gap_flag = 1;
        cout << 2 << endl;
        break;
      }
    }
  }

  if (gap_flag == 0) cout << count_gaps << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    solve(s);
  }

  return 0;
}

