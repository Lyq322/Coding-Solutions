#include <iostream>
#include <queue>

using namespace std;

int N;
char grid[1000][1000];
int visited[1000][1000] = {0};
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, -1, 0, 1};
int ans = 0;
queue<pair<int, int>> bfs;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == '*' && visited[i][j] == 0) {
        ans++;
        visited[i][j] = 1;
        bfs.push({i, j});
        while (!bfs.empty()) {
          int x = bfs.front().first;
          int y = bfs.front().second;
          bfs.pop();
          for (int i = 0; i < 4; i++) {
            int a = di[i] + x;
            int b = dj[i] + y;
            if (a >= 0 && b >= 0 && a < N && b < N && visited[a][b] == 0 && grid[a][b] == '*') {
              bfs.push({a, b});
              visited[a][b] = 1;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}