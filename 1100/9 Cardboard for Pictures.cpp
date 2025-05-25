// 1850E

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

void solve(vll& s, int n, ll c) {
  ll w = 1;
  ll left = 0;

  ll s_sum = 0, s2_sum = 0;
  frange(i, 0, n) {
    s_sum += s[i];
    s2_sum += s[i]*s[i];
  }

  while (left < w) {
    ll cur_sum = 4*w*w*n + 4*w*s_sum + s2_sum;

    if (cur_sum == c) break;
    if (cur_sum < c) {
      left = w;
      w = 2*w;
    } else w = left + (w - left) / 2;
  }

  cout << w << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    ll c;
    cin >> n >> c;

    vll s(n);
    frange(i, 0, n) cin >> s[i];

    solve(s, n, c);
  }

  return 0;
}

