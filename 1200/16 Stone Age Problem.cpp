// 1679B

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

void solve(vll& a, vector<vll>& queries, ll n, ll q) {
  vector<pll> arr;
  ll sum = 0;
  frange(i, 0, n) {
    arr.pb({a[i], -1});
    sum += a[i];
  }

  pll type2 = {0, -2};
  ll i = 0, val;
  for (auto curq : queries) {
    if (curq[0] == 2) {
      sum = n * curq[1];
      type2 = {curq[1], i};
    } else {
      if (type2.S > arr[curq[1]-1].S) val = type2.F;
      else val = arr[curq[1]-1].F;

      sum = sum - val + curq[2];
      arr[curq[1]-1] = {curq[2], i};
    }
    cout << sum << endl;
    i++;
  }
}

int main() {
//  fast_io;
//  int t;
//  cin >> t;
//
//  while (t--) {
//    
//  }

  ll n, q;
  cin >> n >> q;

  vll a(n);
  frange(i, 0, n) cin >> a[i];

  vector<vll> queries(q);
  frange(i, 0, q) {
    ll type;
    cin >> type;

    queries[i].pb(type);
    ll a, b;
    cin >> a;
    queries[i].pb(a);

    if (queries[i][0] == 1) {
      cin >> b;
      queries[i].pb(b);
    }
  }

  solve(a, queries, n, q);

  return 0;
}

