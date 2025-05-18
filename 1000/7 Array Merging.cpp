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

void solve(vll& a, vll& b, ll n) {
  map <ll, ll> count_a, count_b;

  ll count = 1, max_ = -1;
  frange(i, 1, n) {
    if (a[i] == a[i-1]) count++;
    else {
      count_a[a[i-1]] = max(count_a[a[i-1]], count);
      max_ = max(max_, count_a[a[i-1]]);
      count = 1;
    }
  }
  count_a[a[n-1]] = max(count_a[a[n-1]], count);
  max_ = max(max_, count);

  count = 1;
  frange(i, 1, n) {
    if (b[i] == b[i-1]) count++;
    else {
      count_b[b[i-1]] = max(count_b[b[i-1]], count);
      max_ = max(max_, count_b[b[i-1]]);
      max_ = max(max_, count_a[b[i-1]] + count_b[b[i-1]]);
      count = 1;
    }
  }
  count_b[b[n-1]] = max(count_b[b[n-1]], count);
  max_ = max(max_, count_b[b[n-1]]);
  max_ = max(max_, count_b[b[n-1]] + count_a[b[n-1]]);

  cout << max_ << endl;
  
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vll a(n);
    vll b(n);

    frange(i, 0, n) cin >> a[i];
    frange(i, 0, n) cin >> b[i];

    solve(a, b, n);
  }

  return 0;
}

