// 1691B

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

void solve(vll& s, int n) {
  if (n == 1) {
    cout << -1 << endl;
    return;
  }

  vi permute(n);
  int left = 0;
  int i = 1;
  while (i < n) {
    while (i < n && s[i] == s[left]) i++;
    if (i-1 == left) {
      cout << -1 << endl;
      return;
    }

    permute[left++] = i;
    while (left < i) permute[left++] = left;
  }

  print_vec(permute);
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vll s(n);
    frange(i, 0, n) cin >> s[i];

    solve(s, n);
  }

  return 0;
}

