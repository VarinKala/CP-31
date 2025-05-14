#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int solve(vector<int>& v, int k) {
  int n = v.size();

  if (k > 1) cout << "YES" << endl;

  else {
    int sorted_flag = 1;

    for (int i = 1; i < n; i++) {
      if (v[i] < v[i-1]) {
        sorted_flag = 0;
        break;
      }
    } 

    if (sorted_flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    solve(v, k);
  }

  return 0;
}
