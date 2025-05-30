// 1715B

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

void solve(int n, ll k, ll b, ll s) {
  ll covered = k * b;
  ll remaining = s - covered;
  ll coverable = n * (k - 1);

  if (remaining < 0 || remaining > coverable) {
    cout << -1 << endl;
    return;
  }

  vll a(n);
  frange(i, 0, n) a[i] = b / n;
  frange(i, 0, b % n) a[i]++;
  frange(i, 0, n) a[i] *= k;
  int cur = 0, idx = 0;

  while (remaining > 0) {
    cur = min(k-1, remaining);
    a[idx] += cur;
    idx++;
    remaining -= cur;
  }

  print_vec(a);
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    ll k, b, s;

    cin >> n >> k >> b >> s;

    solve(n, k, b, s);
  }

  return 0;
}

