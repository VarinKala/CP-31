// 1820B

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

void solve(string s) {
  ll n = s.size();
  if (n == 1) {
    cout << (int)(s[0] == '1') << endl;
    return;
  }
  
  ll consec = 0;
  ll left = 0;
  if (s[0] == '1' && s[n-1] == '1') {
    while (left < n && s[left] == '1') {
      left++;
      consec++;
    }
    
    ll right = n-1;
    while (right > left && s[right] == '1') {
      right--;
      consec++;
    }

    if (consec == n) {
      cout << n*n << endl;
      return;
    }
  }

  ll right = left+1;
  while (left < n) {
    while (left < n && s[left] == '0') left++;
    if (left == n) break;
    
    right = left + 1;
    while (right < n && s[right] == '1') right++;

    consec = max(consec, right - left);
    left = right + 1;
  }

  cout << ((consec + 1) / 2) * ((consec + 2) / 2) << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    solve(s);
  }

  return 0;
}

