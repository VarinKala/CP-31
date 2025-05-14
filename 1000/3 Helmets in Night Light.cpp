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

void solve(vll& a, vll& b, ll n, ll p) {
  vector<pll> comb;

  frange (i, 0, n) comb.pb({b[i], a[i]});

//  sort(all(comb), [](const auto& p1, const auto& p2) {
//    if (p1.F != p2.F) return p1.F < p2.F;
//    return p1.S >= p2.S;
//  });

  sort(all(comb));

//   ll cost = 0;
//   ll left = 0, right = n - 1;
// 
//   if (comb[0].F >= p) {
//     cout << p * n << endl;
//     return;
//   }
// 
//   while (left < right) {
//     cost += p;
// 
//     if (comb[left].F >= p) {
//       cost += p * (right - left);
//       break;
//     }
// 
//     frange (i, 0, comb[left].S) {
//       right--;
//       cost += comb[left].F;
// 
//       if (left >= right) break;
//     }
//     left++;
//   }
// 
//   cout << cost << endl;
  
  ll cost = p, already_shared = 1;

  for (auto it : comb) {
    ll can_be_shared = it.S;
    ll sharing_cost = it.F;

    if (sharing_cost >= p) break;

    if (already_shared + can_be_shared > n) {
      cost += (n - already_shared) * sharing_cost;
      already_shared = n;
      break;
    }

    cost += can_be_shared * sharing_cost;
    already_shared += can_be_shared;
  }

  cost += (n - already_shared) * p;
  cout << cost << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll n, p;
    cin >> n >> p;

    vll a(n);
    vll b(n);

    frange (i, 0, n) cin >> a[i];
    frange (i, 0, n) cin >> b[i];

    solve(a, b, n, p);
  }

  return 0;
}

