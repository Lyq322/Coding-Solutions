#include <iostream>

using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  int depth[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> depth[i][j];
      //cout << depth[i][j] << ' ';
    }
    //cout << '\n';
  }
  int dk[8] = {1, -1, 1, 0, -1, 1, -1, 0};
  int dl[8] = {1, -1, 0, 1, 1, -1, 0, -1};
  int best = 0;
  for (int k = 0; k < R; k++) {
    for (int l = 0; l < C; l++) {
      if (depth[k][l] > best) {
        for (int m = 0; m < 8; m++) {
          int a = k + dk[m];
          int b = l + dl[m];
          if (a < R && a > -1 && b < C && b > -1) {
            if (depth[a][b] == depth[k][l]) {
              best = depth[a][b];
            }
          }
        }
      }
    }
  }
  cout << best;
  return 0;
}