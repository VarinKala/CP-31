// 1659A

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

void solve(int n, int r, int b) {
  string s = "";
  int div = b + 1;

  if (r - div <= 0) {
    while (r-- > 0) {
      s += "R";
      if (b-- > 0) s += "B";
    }

    cout << s << endl;
    return;
  }

  int per = r / div;
  int extra = r % div;

  while (true) {
    frange(i, 0, per + (extra > 0)) s += "R";
    extra--;
    if (b-- > 0) s += "B";
    else break;
  }

  cout << s << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, r, b;
    cin >> n >> r >> b;

    solve(n, r, b);
  }

  return 0;
}

