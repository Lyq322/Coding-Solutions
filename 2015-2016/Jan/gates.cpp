#include <iostream>
#include <queue>

using namespace std;

int N;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
bool matrix[4001][4001] = {{false}};
bool visited[4001][4001] = {{false}};
queue<pair<int, int>> ff;
char dir;
int ans = 0;

int main() {
  cin >> N;
  int pos1 = 2000, pos2 = 2000;
  matrix[pos1][pos2] = true;
  for (int i = 0; i < N; i++) {
    cin >> dir;
    if (dir == 'S') {
      matrix[pos1 + 1][pos2] = true;
      matrix[pos1 + 2][pos2] = true;
      pos1 += 2;
    }
    else if (dir == 'N') {
      matrix[pos1 - 1][pos2] = true;
      matrix[pos1 - 2][pos2] = true;
      pos1 -= 2;
    }
    else if (dir == 'W') {
      matrix[pos1][pos2 - 1] = true;
      matrix[pos1][pos2 - 2] = true;
      pos2 -= 2;
    }
    else {
      matrix[pos1][pos2 + 1] = true;
      matrix[pos1][pos2 + 2] = true;
      pos2 += 2;
    }
  }
  for (int i = 0; i < 4001; i++) {
    for (int j = 0; j < 4001; j++) {
      if (!matrix[i][j] && !visited[i][j]) {
        ff.push({i, j});
        while (!ff.empty()) {
          int x = ff.front().first;
          int y = ff.front().second;
          ff.pop();
          for (int i = 0; i < 4; i++) {
            int a = x + di[i];
            int b = y + dj[i];
            if (a >= 0 && b >= 0 && a < 4001 && b < 4001 && !matrix[a][b] && !visited[a][b]) {
              visited[a][b] = true;
              ff.push({a, b});
            }
          }
        }
        ans++;
      }
    }
  }
  cout << ans - 1 << endl;
}