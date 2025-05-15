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

void solve(vll& v, int n, ll k) {
  vector<pll> pairs;
  frange(i, 0, n) {
    if (v[i] % k == 0) pairs.pb({k, i+1});
    else pairs.pb({v[i]%k, i+1});
  }

  sort(all(pairs), [](const auto& a, const auto& b) {
    if (a.F != b.F) return a.F > b.F;
    return a.S < b.S;
  });

  frange(i, 0, (int)pairs.size()) cout << pairs[i].S << " ";
  
  cout << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    ll k;
    cin >> n >> k;

    vll v(n);
    frange (i, 0, n) cin >> v[i];

    solve(v, n, k);
  }

  return 0;
}

