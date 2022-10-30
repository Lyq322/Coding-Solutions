#include <iostream>
#include <set>
 
using namespace std;
 
int x, n;
set<int> lights;
multiset<int> gaps;
 
int main() {
  cin >> x >> n;
  lights.insert(0);
  lights.insert(x);
  gaps.insert(x);
  int l;
  for (int i = 0; i < n; i++) {
    cin >> l;
    auto it1 = lights.upper_bound(l);
    auto it2 = it1;
    --it2;
    lights.insert(l);
    gaps.erase(gaps.find(*it1 - *it2));
    gaps.insert(*it1 - l);
    gaps.insert(l - *it2);
    auto ans = gaps.end();
    --ans;
    cout << *ans << ' ';
  }
} 