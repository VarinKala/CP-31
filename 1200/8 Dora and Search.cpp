// 1793C

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

void solve(vi& a, int n) {
  int left = 0, right = n-1;
  vi sorted_a = a;
  sort(all(sorted_a));
  int min_el = 0, max_el = n-1;

  while (left < n) {
    if (a[left] == sorted_a[min_el]) {
      left++;
      min_el++;
    } else if (a[left] == sorted_a[max_el]) {
      left++;
      max_el--;
    } else if (a[right] == sorted_a[min_el]) {
      right--;
      min_el++;
    } else if (a[right] == sorted_a[max_el]) {
      right--;
      max_el--;
    } else break;
  }

  if (min_el > max_el) cout << -1 << endl;
  else cout << left+1 << " " << right+1 << endl;
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

