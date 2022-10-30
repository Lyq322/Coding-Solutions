#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> pii;
 
int n;
multiset<pii> end_time;
vector<pair<pii, int>> customers;
int rooms[200000] = {0};
 
int main() {
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    customers.push_back({{a, b}, i});
  }
  sort(customers.begin(), customers.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    pii customer = customers[i].first;
    auto it = end_time.lower_bound({customer.first, 0});
    if (it == end_time.begin()) {
      end_time.insert({customer.second, ans + 1});
      ans++;
      rooms[customers[i].second] = ans;
    }
    else {
      --it;
      pii room = *it;
      end_time.erase(end_time.find(*it));
      end_time.insert({customer.second, room.second});
      rooms[customers[i].second] = room.second;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << rooms[i] << ' ';
  }
  cout << endl;
} 