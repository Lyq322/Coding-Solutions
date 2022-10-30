#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
int n;
vector<vector<int>> cows;
int visited[200000] = {0};
 
int main() {
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++) {
    cows.push_back({});
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    cows[a].push_back(b);
    cows[b].push_back(a);
  }
  stack<pair<int, int>> s;
  s.push({0, 0});
  visited[0] = 1;
  pair<int, int> ans = {0, 0};
  while (!s.empty()) {
    pair<int, int> cur = s.top();
    s.pop();
    for (int i = 0; i < cows[cur.first].size(); i++) {
      int next = cows[cur.first][i];
      if (visited[next] == 0) {
        visited[next] = 1;
        s.push({next, cur.second + 1});
        if (cur.second + 1 > ans.second) {
          ans = {next, cur.second + 1};
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  stack<pair<int, int>> s2;
  s2.push({ans.first, 0});
  visited[ans.first] = 1;
  ans = {0, 0};
  while (!s2.empty()) {
    pair<int, int> cur = s2.top();
    s2.pop();
    for (int i = 0; i < cows[cur.first].size(); i++) {
      int next = cows[cur.first][i];
      while (visited[next] == 0) {
        visited[next] = 1;
        s2.push({next, cur.second + 1});
        if (cur.second + 1 > ans.second) {
          ans = {next, cur.second + 1};
        }
      }
    }
  }
  cout << ans.second << endl;
} 