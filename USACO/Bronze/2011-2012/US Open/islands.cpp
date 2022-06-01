#include <iostream>
#include <algorithm>

using namespace std;

int n;
int islands[100000];
pair<int, int> sortedIslands[100000];

int main() {
  cin >> n;
  string s = "";
  for (int i = 0; i < n; i++) {
    cin >> islands[i];
    sortedIslands[i] = {islands[i], i};
    s += 'L';
  }
  sort(sortedIslands, sortedIslands + n);
  int island = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cout << s << endl;
    if (sortedIslands[i].second == 0) {
      if (s[sortedIslands[i].second + 1] == 'W') {
        island--;
      }
    }
    else if (sortedIslands[i].second == n - 1) {
      if (s[sortedIslands[i].second - 1] == 'W') {
        island--;
      }
    }
    else {
      if (s[sortedIslands[i].second + 1] == 'L' && s[sortedIslands[i].second - 1] == 'L') {
        island++;
      } 
      else if (s[sortedIslands[i].second + 1] == 'W' && s[sortedIslands[i].second - 1] == 'W') {
        island--;
      }
    }
    s[sortedIslands[i].second] = 'W';
    if (i == n - 1 || sortedIslands[i].first != sortedIslands[i + 1].first) {
      ans = max(ans, island);
    }
  }
  cout << ans << endl;
}