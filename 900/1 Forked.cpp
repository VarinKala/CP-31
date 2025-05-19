// 1904A

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

void solve(int a, int b, int xk, int yk, int xq, int yq) {
//  vi dx = {-1, 1, -1, 1};
//  vi dy = {-1, -1, 1, 1};
  vi dx{-1, 1, -1, 1};
  vi dy{-1, -1, 1, 1};
  set<pii> king_sq, queen_sq;

  frange (i, 0, 4) {
    king_sq.insert({xk + dx[i]*a, yk + dy[i]*b});
    king_sq.insert({xk + dx[i]*b, yk + dy[i]*a});

    queen_sq.insert({xq + dx[i]*a, yq + dy[i]*b});
    queen_sq.insert({xq + dx[i]*b, yq + dy[i]*a});
  }

  int ans = 0;
  for (auto pos: king_sq) {
    if (queen_sq.find(pos) != queen_sq.end()) ans++;
  }

  cout << ans << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;

    solve(a, b, xk, yk, xq, yq);
  }

  return 0;
}

