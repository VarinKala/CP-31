// 1725B

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

// Debug macro (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& p, int n, ll d) {
  sort(all(p));

  int teams = 0, left = 0, right = n-1;
  int members = 0;
  while (left <= right) {
    members = d / p[right];
    if (left + members <= right) {
      teams++;
      left = left + members;
      right--;
    } else break;
  }

  cout << teams << endl;
}

int main() {
  fast_io;
//   int t;
//   cin >> t;
// 
//   while (t--) {
  int n;
  ll d;
  cin >> n >> d;

  vll p(n);
  frange(i, 0, n) cin >> p[i];
  
  solve(p, n, d);
//  }

  return 0;
}

