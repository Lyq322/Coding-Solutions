#include <iostream>

using namespace std;

int R;
int** pinball;
int ans = 0;

void dfs(int i, int j, int score) {
  if (i == R - 1) {
    if (score > ans) {
      ans = score;
    }
    return;
  }
  dfs(i+1, j, score + pinball[i+1][j]);
  dfs(i+1, j+1, score + pinball[i+1][j+1]);
}

int main() {
  cin >> R;
  pinball = new int*[R];
  for (int i = 0; i < R; i++) {
    pinball[i] = new int[R];
    for (int j = 0; j < i + 1; j++) {
      cin >> pinball[i][j];
    }
  }
  dfs(0, 0, pinball[0][0]);
  cout << ans << endl;
}