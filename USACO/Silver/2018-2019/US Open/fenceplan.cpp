#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

pii acorns[100000];
int n, m;
vector<vector<int>> colors;
bool visited[100000];
int max_x, max_y, min_x, min_y;
int ans = -1;

void dfs(int pos) {
  for (int i = 0; i < colors[pos].size(); i++) {
    if (!visited[colors[pos][i]]) {
      int next = colors[pos][i];
      if (acorns[next].first < min_x || min_x == -1) {
        min_x = acorns[next].first;
      }
      if (acorns[next].first > max_x) {
        max_x = acorns[next].first;
      }
      if (acorns[next].second < min_y || min_y == -1) {
        min_y = acorns[next].second;
      }
      if (acorns[next].second > max_y) {
        max_y = acorns[next].second;
      }
      visited[next] = true;
      dfs(next);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> acorns[i].first >> acorns[i].second;
  }
  int a, b;
  for (int i = 0; i < n; i++) {
    colors.push_back({});
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    colors[a].push_back(b);
    colors[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      min_x = -1;
      min_y = -1;
      max_x = 0;
      max_y = 0;
      dfs(i);
      cout << max_x - min_x << ' ' << max_y - min_y << endl;
      int perimeter = 2 * (max_x - min_x + max_y - min_y);
      if (perimeter < ans || ans == -1) {
        ans = perimeter;
      }
    }
  }
  cout << ans << endl;
} 