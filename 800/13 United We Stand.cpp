// 1859A

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

void solve(vll& a, int n) {
  vll b;
  vll c;

  map<int, int> counter;
  ll max_element = 0;
  frange(i, 0, n) {
    max_element = max(max_element, a[i]);
    counter[a[i]]++;
  }

  if (counter.size() <= 1) {
    cout << -1 << endl;
    return;
  }

  frange(i, 0, n) {
    if (a[i] == max_element) c.pb(a[i]);
    else b.pb(a[i]);
  }

  cout << b.size() << " " << c.size() << endl;
  print_vec(b);
  print_vec(c);
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

