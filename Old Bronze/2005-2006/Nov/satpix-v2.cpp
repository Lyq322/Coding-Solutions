#include <iostream>

using namespace std;

int W, H;
char** grid;
int sz;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int ans = 0;

void dfs(int x, int y) {
  //cout << "x " << x << " y " << y << endl;
  for (int i = 0; i < 4; i++) {
    int a = di[i] + x;
    int b = dj[i] + y;
    if (a >= 0 && b >= 0 && a < H && b < W) {
      if (grid[a][b] == '*') {
        sz++;
        grid[a][b] = '.';
        dfs(a, b);
      }
    }
  }
}

int main() {
  cin >> W >> H;
  grid = new char*[H];
  for (int i = 0; i < H; i++) {
    grid[i] = new char[W];
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '*') {
        grid[i][j] = '.';
        sz = 1;
        dfs(i, j);
        if (sz > ans) {
          ans = sz;
        }
      }
    }
  }
  cout << ans << endl;
}