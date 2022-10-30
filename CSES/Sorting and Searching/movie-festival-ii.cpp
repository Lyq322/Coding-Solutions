#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
 
int k, n;
multiset<int> top;
pii schedule[200000];
 
bool comp(pii a, pii b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}
 
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> schedule[i].first >> schedule[i].second;
  }
  sort(schedule, schedule + n, comp);
  for (int i = 0; i < k; i++) {
    top.insert(0);
  }
  int start, finish;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    start = schedule[i].first;
    finish = schedule[i].second;
    auto it = top.upper_bound(start);
    if (it == top.begin()) {
      continue;
    }
    ans++;
    top.erase(prev(it));
    top.insert(finish);
  }
  cout << ans << endl;
} 