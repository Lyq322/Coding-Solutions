#include <iostream>
#include <vector>
#include <stack>
#include <set>
 
using namespace std;
 
int n, m;
vector<vector<int>> cows;
vector<vector<int>> reversed;
int visited[100000] = {0};
set<int> numbers;
bool cycle = true;
int example;
 
void dfs(vector<vector<int>> arr) {
  stack<int> dfsdfs;
  dfsdfs.push(0);
  while (!dfsdfs.empty()) {
    int pos = dfsdfs.top();
    dfsdfs.pop();
    for (int i = 0; i < arr[pos].size(); i++) {
      int next = arr[pos][i];
      if (visited[next] == 0) {
        visited[next] = 1;
        numbers.insert(next);
        dfsdfs.push(next);
      }
    }
  }
}
 
int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < n; i++) {
    cows.push_back({});
    reversed.push_back({});
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cows[a - 1].push_back(b - 1);
    reversed[b - 1].push_back(a - 1);
  }
  visited[0] = 1;
  numbers.insert(0);
  dfs(cows);
  if (numbers.size() != n) {
    example = n - 1;
    int index = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
      if (*it != index) {
        example = index;
        break;
      }
      index++;
    }
    cycle = false;
    cout << "NO\n";
    cout << 1 << ' ' << example + 1 << endl;
  }
  if (cycle) {
    numbers.clear();
    for (int i = 0; i < n; i++) {
      visited[i] = 0;
    }
    visited[0] = 1;
    numbers.insert(0);
    dfs(reversed);
    if (numbers.size() != n) {
      int index = 0;
      example = n - 1;
      for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it != index) {
          example = index;
          break;
        }
        index++;
      }
      cycle = false;
      cout << "NO\n";
      cout << example + 1 << ' ' << 1 << endl;
    }
    if (cycle) {
      cout << "YES\n";
    }
  }
} 
