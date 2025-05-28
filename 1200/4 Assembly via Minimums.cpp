// 1857C

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

void solve(vll& b, int n, int n2) {
  sort(all(b));

  int idx = 0;
  vll a(n);

  int i = 0, prev = 0;
  while (i < n2) {
    while (i < prev + n-idx-1 && b[i] == b[prev]) i++;

    a[idx++] = b[prev];
    prev = i;
  }

  frange(i, idx, n) a[i] = a[i-1];

  print_vec(a);
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int n2 = n * (n-1) / 2;

    vll b(n2);
    frange(i, 0, n2) cin >> b[i];

    solve(b, n, n2);
  }

  return 0;
}

