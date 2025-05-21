// 1807D

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

void solve(vll& v, vi& l, vi& r, vll& k, int n, int q) {
  vll presum(n+1);
  presum[0] = 0;

  frange(i, 0, n) presum[i+1] = presum[i] + v[i];

  int original_check = (presum[n] % 2) ? 1 : 0;

  frange(i, 0, q) {
    ll cur_sum = presum[r[i]] - presum[l[i]-1];
    ll k_sum = (r[i]-l[i]+1) * k[i];

    int cur_check = (cur_sum%2 == k_sum%2) ? original_check : 1 - original_check;

    if (cur_check) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vll v(n);
    frange(i, 0, n) cin >> v[i];

    vi l(q);
    vi r(q);
    vll k(q);

    frange(i, 0, q) cin >> l[i] >> r[i] >> k[i];

    solve(v, l, r, k, n, q);
  }

  return 0;
}

