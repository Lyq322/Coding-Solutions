#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
set<int> towers;
vector<int> cities;

int main() {
  cin >> n >> m;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cities.push_back(a);
  }
  sort(cities.begin(), cities.end());
  for (int i = 0; i < m; i++) {
    cin >> a;
    towers.insert(a);
  }
  int minimum;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto it2 = towers.lower_bound(cities[i]);
    if (it2 == towers.end()) {
      --it2;
      minimum = cities[i] - *it2;
    }
    else if (it2 == towers.begin()) {
      minimum = *it2 - cities[i];
    }
    else {
      auto it1 = it2;
      --it1;
      minimum = min(*it2 - cities[i], cities[i] - *it1);
    }
    ans = max(ans, minimum);
  }
  cout << ans << endl;
} 