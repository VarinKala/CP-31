// 1703E

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

void solve(vector<vll>& a, ll n) {
  ll change = 0;
  
  frange(i, 0, n/2) {
    frange(j, 0, (n+1)/2) {
      ll count = 0;
      if (a[i][j] == '1') count++;
      if (a[j][n-i-1] == '1') count++;
      if (a[n-j-1][i] == '1') count++;
      if (a[n-i-1][n-j-1] == '1') count++;
      
      if (count == 0 || count == 4) ;
      else if (count == 2) change += 2;
      else change++;
    }
  }

  cout << change << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vector<vll> a(n, vll (n));
    string s;
    frange(i, 0, n) {
      cin >> s;
      frange(j, 0, n) a[i][j] = s[j];
    }

    solve(a, n);
  }

  return 0;
}

