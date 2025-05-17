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

void solve(vi& a, int n) {
  map<int, int> counter;

  frange(i, 0, n) {
    if (counter.count(a[i])) counter[a[i]] += 1;
    else counter[a[i]] = 1;
  }

  if (counter.size() > 2) cout << "No" << endl;

  else {
    vi key;

    for (auto [k, v] : counter) key.pb(k);

    if (counter.size() <= 1) cout << "Yes" << endl;
    else if (counter[key[0]] - counter[key[1]] >= -1 && counter[key[0]] - counter[key[1]] <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n);
  }

  return 0;
}

