// 1692E

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
#define frange(i, a, b) for (ll i = (a); i < (b); ++i)
#define frev(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define print_vec(x) for (ll i = 0; i < (ll)x.size(); i++) cout << x[i] << " "; cout << endl
#define pb push_back
#define F first
#define S second

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

void solve(vll& a, ll n, ll s) {
//   ll sum = 0, left = 0;
//   vll gaps;
//   frange(i, 0, n) {
//     sum += a[i];
//     if (a[i]) {
//       gaps.pb(i - left);
//       left = i + 1;
//     }
//   }
//   gaps.pb(n - left);
// 
//   if (s > sum) {
//     cout << -1 << endl;
//     return;
//   }
//   if (s == sum) {
//     cout << 0 << endl;
//     return;
//   }
// 
//   left = 0;
//   ll count = 0, right = sum;
//   bool choice = false, done = false;
//   ll cont = -1;
//   while (sum > s) {
// //    debug(sum);
//     if (!choice) {
// //      cout << 1 << endl;
//       while (left < cont) {
//         sum--;
//         count += gaps[left] + 1;
//         left++;
//         if (sum == s) {
//           done = true;
//           break;
//         }
//       }
//       if (!done && gaps[left] < gaps[right]) {
//         sum--;
//         count += gaps[left] + 1;
//         left++;
//         if (sum == s) done = true;
//       }
//     } else {
// //      cout << 2 << endl;
//       while (right > cont) {
//         sum--;
//         count += gaps[right] + 1;
//         right--;
//         if (sum == s) {
//           done = true;
//           break;
//         }
//       }
//       if (!done && gaps[right] < gaps[left]) {
//         sum--;
//         count += gaps[right] + 1;
//         right--;
//         if (sum == s) done = true;
//       }
//     }
// 
//     if (done) break;
// 
//     ll l = left, r = right;
// //    debug(l);
// //    debug(r);
//     while (l < r && gaps[l] == gaps[r]) {
//       l++;
//       r--;
//     }
//     if (l < r) {
//       if (gaps[l] < gaps[r]) {
// //        cout << 3 << endl;
//         choice = false;
//         cont = l;
//       } else {
// //        cout << 4 << endl;
//         choice = true;
//         cont = r;
//       }
//     } else {
// //      cout << 5 << endl;
//       cont = right;
//       choice = false;
//     }
// //    cout << endl << endl;
//   }
// 
//   cout << count << endl;
  
  map<ll, ll> reg;
  ll sum = 0;
  reg[0] = -1;
  ll len = -1;

  frange(i, 0, n) {
    sum += a[i];
    if (reg.count(sum - s)) len = max(len, i - reg[sum-s]);
    if (!reg.count(sum)) reg[sum] = i;
  }

  if (len == -1) cout << -1 << endl;
  else cout << n - len << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, s;
    cin >> n >> s;

    vll a(n);
    frange(i, 0, n) cin >> a[i];

    solve(a, n, s);
  }

  return 0;
}

