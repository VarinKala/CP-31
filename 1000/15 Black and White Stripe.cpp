// 1690D

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

void solve(string s, int n, int k) {
  int min_fill = INT_MAX;
  vi prefix(n+1, 0);

  frange(i, 0, n) prefix[i+1] = prefix[i] + (s[i] == 'W');
  frange(i, 0, n-k+1) min_fill = min(min_fill, prefix[i+k] - prefix[i]);
  
  cout << min_fill << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    solve(s, n, k);
  }

  return 0;
}

