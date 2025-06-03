// 1845A

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

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(int n, int k, int x) {
  if (x != 1) {
    cout << "YES" << endl;
    cout << n << endl;
    frange(i, 0, n) cout << 1 << " ";
    cout << endl;
    return;
  }

  if (k == 1 || (k == 2 && n % 2)) cout << "NO" << endl;
  else if (n % 2 == 0) {
    cout << "YES" << endl;
    cout << n / 2 << endl;
    frange(i, 0, n/2) cout << 2 << " ";
    cout << endl;
  } else {
    cout << "YES" << endl;
    cout << (n-3)/2 + 1 << endl;
    frange(i, 0, (n-3)/2) cout << 2 << " ";
    cout << 3 << endl;
  }
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    solve(n, k, x);
  }

  return 0;
}

