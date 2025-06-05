// 1620B

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

void solve(vll& hor_down, vll& hor_up, vll& ver_left, vll& ver_right, ll w, ll h) {
  ll max_area = 0;
  max_area = max(max_area, h * (hor_down[hor_down.size()-1] - hor_down[0]));
  max_area = max(max_area, h * (hor_up[hor_up.size()-1] - hor_up[0]));
  max_area = max(max_area, w * (ver_left[ver_left.size()-1] - ver_left[0]));
  max_area = max(max_area, w * (ver_right[ver_right.size()-1] - ver_right[0]));

  cout << max_area << endl;
}

int main() {
  fast_io;
  int t;
  cin >> t;

  while (t--) {
    ll w, h;
    cin >> w >> h;

    ll k;
    cin >> k;
    vll hor_down(k);
    frange(i, 0, k) cin >> hor_down[i];

    cin >> k;
    vll hor_up(k);
    frange(i, 0, k) cin >> hor_up[i];

    cin >> k;
    vll ver_left(k);
    frange(i, 0, k) cin >> ver_left[i];

    cin >> k;
    vll ver_right(k);
    frange(i, 0, k) cin >> ver_right[i];

    solve(hor_down, hor_up, ver_left, ver_right, w, h);
  }

  return 0;
}

