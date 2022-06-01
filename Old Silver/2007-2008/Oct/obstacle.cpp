#include <iostream>
#include <queue>

using namespace std;

int n;
char grid[100][100];
bool visited[100][100] = {{0}};
int sx, sy, fx, fy;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        sx = i;
        sy = j;
      }
      if (grid[i][j] == 'B') {
        fx = i;
        fy = j;
      }
    }
  }
  queue<pair<pair<int, int>, int>> q;
  q.push({{sx, sy}, 0});
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int d = q.front().second;
    q.pop();
    if (grid[x][y] == 'B') {
      cout << d - 1 << endl;
      break;
    }
    for (int i = x + 1; i < n; i++) {
      if (grid[i][y] == 'x') {
        break;
      }
      if (!visited[i][y]) {
        visited[i][y] = true;
        q.push({{i, y}, d + 1});
      }
    }
    for (int i = x - 1; i >= 0; i--) {
      if (grid[i][y] == 'x') {
        break;
      }
      if (!visited[i][y]) {
        visited[i][y] = true;
        q.push({{i, y}, d + 1});
      }
    }
    for (int i = y + 1; i < n; i++) {
      if (grid[x][i] == 'x') {
        break;
      }
      if (!visited[x][i]) {
        visited[x][i] = true;
        q.push({{x, i}, d + 1});
      }
    }
    for (int i = y - 1; i >= 0; i--) {
      if (grid[x][i] == 'x') {
        break;
      }
      if (!visited[x][i]) {
        visited[x][i] = true;
        q.push({{x, i}, d + 1});
      }
    }
  }
}