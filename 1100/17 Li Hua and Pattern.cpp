// 1797B

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

void solve(vector<vll>& a, ll n, ll k) {
  ll mid = (n * n) / 2;
  ll i = 0, j = n*n-1;
  while (i < mid) {
    if (a[i/n][i%n] != a[j/n][j%n]) k--;
    i++;
    j--;
  }

  if (k < 0 || (n % 2 == 0 && k % 2)) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, k;
    cin >> n >> k;

    vector<vll> a(n, vll (n, 0));
    frange(i, 0, n) {
      frange(j, 0, n) cin >> a[i][j];      
    }

    solve(a, n, k);
  }

  return 0;
}

