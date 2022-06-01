#include <iostream>

using namespace std;

int N, M;
char grid[50][50];
int ans = 0;

int find(char m, char o) {
  int a = 0;
  if (m == o) {
    return 0;
  }
  if (o == 'o' || m == 'm') {
    return 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == m) {
        if (i <= N-3 && grid[i+1][j] == o && grid[i+2][j] == o) {
          a++;
        }
        if (j <= M-3 && grid[i][j+1] == o && grid[i][j+2] == o) {
          a++;
        }
        if (i >= 2 && grid[i-1][j] == o && grid[i-2][j] == o) {
          a++;
        }
        if (j >= 2 && grid[i][j-1] == o && grid[i][j-2] == o) {
          a++;
        }
        if (i <= N-3 && j <= M-3 && grid[i+1][j+1] == o && grid[i+2][j+2] == o) {
          a++;
        }
        if (i >= 2 && j >= 2 && grid[i-1][j-1] == o && grid[i-2][j-2] == o) {
          a++;
        }
        if (i <= N-3 && j >= 2 && grid[i+1][j-1] == o && grid[i+2][j-2] == o) {
          a++;
        }
        if (i >= 2 && j <= M-3 && grid[i-1][j+1] == o && grid[i-2][j+2] == o) {
          a++;
        }
      }
    }
  }
  return a;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << "i " << i << " j " << j << endl;
      if (j < M - 1 && grid[i][j] == grid[i][j+1]) {
        cout << "left right" << endl;
        if (j != 0) {
          ans = max(ans, find(grid[i][j-1], grid[i][j]));
        }
        if (j != M-2) {
          ans = max(ans, find(grid[i][j+2], grid[i][j]));
        }
      }
      else if (i < N - 1 && grid[i][j] == grid[i+1][j]) {
        cout << "up down" << endl;
        if (i != 0) {
          ans = max(ans, find(grid[i-1][j], grid[i][j]));
        }
        if (i != N-2) {
          ans = max(ans, find(grid[i+2][j], grid[i][j]));
        }
      }
      else if (i < N - 1 && j < M - 1 && grid[i][j] == grid[i+1][j+1]) {
        cout << "diagonal" << endl;
        if (i != 0 && j != 0) {
          ans = max(ans, find(grid[i-1][j-1], grid[i][j]));
        }
        if (i != N-2 && j != M-2) {
          ans = max(ans, find(grid[i+2][j+2], grid[i][j]));
        }
      }
    }
  }
  cout << ans << endl;
}