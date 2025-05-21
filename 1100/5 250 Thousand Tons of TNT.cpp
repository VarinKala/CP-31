// 1899B

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

void solve(vll& a, int n) {
  vll presum(n+1);
  presum[0] = 0;
  ll ans = 0, maxi = 0, mini = 0, cur_truck = 0;

  frange(i, 0, n) presum[i+1] = presum[i] + a[i];

  int i = 1;
  while (i <= (int)sqrt(n)) {
    if (n % i) {
      i++;
      continue;
    }

    int pro = n / i;
    
    maxi = mini = presum[i];
    for (int j = i; j < n; j += i) {
      cur_truck = presum[j+i] - presum[j];
      maxi = max(maxi, cur_truck);
      mini = min(mini, cur_truck);
    }
    ans = max(ans, maxi - mini);

    maxi = mini = presum[pro];
    for (int j = pro; j < n; j += pro) {
      cur_truck = presum[j+pro] - presum[j];
      maxi = max(maxi, cur_truck);
      mini = min(mini, cur_truck);
    }
    ans = max(ans, maxi - mini);
    
    i++;
  }

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

