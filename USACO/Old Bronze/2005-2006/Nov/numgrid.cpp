#include <iostream>
#include <set>

using namespace std;

char grid[5][5];
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
set<string> ans;

void dfs(int x, int y, int moves, string pos) {
  if (moves == 5) {
    ans.insert(pos);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int a = x + di[i];
    int b = y + dj[i];
    if (a >= 0 && b >= 0 && a < 5 && b < 5) {
      dfs(a, b, moves + 1, pos + grid[a][b]);
    }
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> grid[i][j];
    }
  }  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      dfs(i, j, 0, string(1, grid[i][j]));
    }
  }
  cout << ans.size();
}