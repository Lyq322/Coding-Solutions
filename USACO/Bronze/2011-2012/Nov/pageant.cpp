#include <iostream>

using namespace std;

int N, M;
char grid[50][50];
int mark[50][50];
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int ans = -1;

void ff(int x, int y, int n) {
  int a, b;
  for (int i = 0; i < 4; i++) {
    a = di[i] + x;
    b = dj[i] + y;
    if (a >= 0 && b >= 0 && a < N && b < M && mark[a][b] == 0 && grid[a][b] == 'X') {
      mark[a][b] = n;
      ff(a, b, n);
    }
  }
}

int main() {
  cin >> N >> M;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      grid[i][j] = s.at(j);
      mark[i][j] = 0;
    }
  }
  bool br = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'X' && mark[i][j] == 0) {
        mark[i][j] = 1;
        ff(i, j, 1);
        br = true;
        break;
      }
    }
    if (br) {
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'X' && mark[i][j] == 0) {
        mark[i][j] = 2;
        ff(i, j, 2);
        break;
      }
    }
  }
  int d;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mark[i][j] == 1) {
        for (int k = 0; k < N; k++) {
          for (int l = 0; l < M; l++) {
            if (mark[k][l] == 2) {
              d = abs(k - i) + abs(l - j);
              if (ans == -1 || d < ans) {
                ans = d;
              }
            }
          }
        }
      }
    }
  }
  cout << ans - 1 << endl;
}