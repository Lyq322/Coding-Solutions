#include <iostream>

using namespace std;

int N;
int grid[102][102];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int visited[102][102];
int ans = 0;

void dfs(int row, int column) {
  for (int i = 0; i < 4; i++) {
    int a = row + di[i];
    int b = column + dj[i];
    if (a >= 0 && b >= 0 && a <= 101 && b <= 101 && visited[a][b] == 0) {
      if (grid[a][b] == 1) {
        ans++;
      }
      else {
        visited[a][b] = 1;
        dfs(a, b);
      }
    }
  }
}

int main() {
  cin >> N;
  int a, b;
  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < 102; j++) {
      grid[i][j] = 0;
      visited[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    grid[a][b] = 1;
  }
  dfs(0, 0);
  cout << ans << endl;
}