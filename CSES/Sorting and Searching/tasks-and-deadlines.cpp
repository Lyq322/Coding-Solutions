#include <iostream>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
 
int n;
pii tasks[200000];
 
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tasks[i].first >> tasks[i].second;
  }
  sort(tasks, tasks + n);
  ll ans = 0;
  ll current_time = 0;
  for (int i = 0; i < n; i++) {
    ans += tasks[i].second - current_time - tasks[i].first;
    current_time += tasks[i].first;
  }
  cout << ans << endl;
} 