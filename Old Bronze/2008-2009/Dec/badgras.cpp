#include <iostream>
#include <queue>

using namespace std;

int n, m;
int grid[1000][1000];
bool visited[1000][1000] = {{0}};
int di[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != 0 && !visited[i][j]) {
        ans++;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 8; k++) {
            int a = x + di[k];
            int b = y + dj[k];
            if (a >= 0 && b >= 0 && a < n && b < m && !visited[a][b] && grid[a][b] != 0) {
              q.push({a, b});
              visited[a][b] = true;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}