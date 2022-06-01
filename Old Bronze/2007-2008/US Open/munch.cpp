#include <iostream>
#include <queue>

using namespace std;

int r, c;
char grid[100][100];
queue<pair<pair<int, int>, int>> path;
int sx, sy, fx, fy;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
bool visited[100][100];

int main() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'B') {
        fx = i;
        fy = j;
      } 
      else if (grid[i][j] == 'C') {
        sx = i;
        sy = j;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      visited[i][j] = false;
    }
  }
  path.push({{sx, sy}, 0});
  visited[sx][sy] = true;
  while (!path.empty()) {
    int x = path.front().first.first;
    int y = path.front().first.second;
    int length = path.front().second;
    path.pop();
    if (x == fx && y == fy) {
      cout << length - 1 << endl;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int a = x + di[i];
      int b = y + dj[i];
      if (a >= 0 && b >= 0 && a < r && b < c && !visited[a][b] && grid[a][b] != '*') {
        path.push({{a, b}, length + 1});
        visited[a][b] = true;
      }
    }
  }
}