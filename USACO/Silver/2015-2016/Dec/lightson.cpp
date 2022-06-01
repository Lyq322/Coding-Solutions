#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int rooms[101][101];
bool light[101][101];
bool visited[101][101];
vector<pair<int, int>> switches[101][101];
queue<pair<int, int>> path;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
  cin >> n >> m;
  int x, y, a, b;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> a >> b;
    switches[x][y].push_back({a, b});
  }
  light[1][1] = true;
  path.push({1, 1});
  while (!path.empty()) {
    x = path.front().first;
    y = path.front().second;
    path.pop();
    visited[x][y] = true;
    for (int i = 0; i < switches[x][y].size(); i++) {
      int pos_x = switches[x][y][i].first;
      int pos_y =  switches[x][y][i].second;
      if (!light[pos_x][pos_y]) {
        light[pos_x][pos_y] = true;
        bool adjacent = false;
        for (int j = 0; j < 4; j++) {
          int a = di[j] + pos_x;
          int b = dj[j] + pos_y;
          if (a > 0 && b > 0 && a <= n && m <= n) {
            if (visited[a][b]) {
              adjacent = true;
              break;
            }
          }
        }
        if (adjacent && !visited[pos_x][pos_y]) {
          path.push({pos_x, pos_y});
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      int a = di[i] + x;
      int b = dj[i] + y;
      if (a > 0 && b > 0 && a <= n && b <= n) {
        if (!visited[a][b] && light[a][b]) {
          path.push({a, b});
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << light[i][j] << ' ';
    }
    cout << endl;
  }
}