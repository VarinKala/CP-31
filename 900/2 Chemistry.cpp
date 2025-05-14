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

void solve(string s, int n, int k) {
  map<char, int> counter;

  frange (i, 0, n) {
    if (counter.count(s[i])) counter[s[i]]++;
    else counter[s[i]] = 1;
  }

  int count = 0;
  for (auto &[key, val]: counter) {
    if (val % 2 == 1) count++;
  }

  if (count - 1 > k) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    solve(s, n, k);
  }

  return 0;
}

