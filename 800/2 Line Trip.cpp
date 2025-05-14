#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int solve(vector<int>& v, int x) {
  int max_dist = max(v[0], 2*(x - v.back()));

  for (int i = 1; i < v.size(); i++) {
    if ((v[i] - v[i-1]) > max_dist) max_dist = v[i] - v[i-1];
  }

  cout << max_dist << endl;

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    solve(v, x);
  }

  return 0;
}
