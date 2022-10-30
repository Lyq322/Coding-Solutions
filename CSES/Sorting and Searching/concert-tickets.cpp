#include <iostream>
#include <set>
 
using namespace std;
 
int n, m;
multiset<int> tickets;
 
int main() {
  cin >> n >> m;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    tickets.insert(a);
  }
  int q;
  for (int i = 0; i < m; i++) {
    cin >> q;
    auto t = tickets.upper_bound(q);
    if (t == tickets.begin()) {
      cout << -1 << endl;
    }
    else {
      cout << *(--t) << endl;
      tickets.erase(t);
    }
  }
} 