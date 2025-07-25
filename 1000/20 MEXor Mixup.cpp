// 1567B

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

void solve(ll a, ll b) {
  ll count = a;
  ll xor_ = 0;

  frange(i, (a / 4) * 4, a) xor_ = xor_ ^ i;

  if (xor_ == b) cout << count << endl;
  else if ((xor_ ^ b) != a) cout << count + 1 << endl;
  else cout << count + 2 << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll a, b;
    cin >> a >> b;

    solve(a, b);
  }

  return 0;
}

