#include <iostream>
#include <vector>
 
using namespace std;
 
int n;
vector<vector<int>> tree;
int count[200000] = {0};
int visited[200000] = {0};
 
void dfs(int node) {
  count[node] = 1;
  for (int i = 0; i < tree[node].size(); i++) {
    if (visited[tree[node][i]] == 0) {
      visited[tree[node][i]] = 1;
      dfs(tree[node][i]);
      count[node] += count[tree[node][i]];
    }
  }
}
 
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    tree.push_back({});
  }
  int a;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    tree[a - 1].push_back(i + 1);
  }
  visited[0] = 0;
  dfs(0);
  for (int i = 0; i < n; i++) {
    cout << count[i] - 1 << ' ';
  }
  cout << endl;
} 