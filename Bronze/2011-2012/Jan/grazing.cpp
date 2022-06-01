#include <iostream>

using namespace std;

int K;
int ans = 0;
int visited[5][5] = {0};
char maze[5][5];

void dfs(int x, int y, int length) {
  //cout << "x " << x + 1 << " y " << y + 1 << endl;
  //cin.ignore();
  if (x == 4 && y == 4) {
    //cout << length << endl;
    if (length + 1 == 25 - K) {
      //for (int i = 0; i < 5; i++) {
      //  for (int j = 0; j < 5; j++) {
      //    cout << visited[i][j] << ' ';
      //  }
      //  cout << endl;
      //}
      ans++;
    }
    return;
  }
  if (y + 1 < 5) {
    if (visited[x][y+1] == 0 && maze[x][y+1] != '#') {
      visited[x][y+1] = 1;
      dfs(x, y+1, length + 1);
      visited[x][y+1] = 0;
    }
  }
  if (x + 1 < 5) {
    if (visited[x+1][y] == 0 && maze[x+1][y] != '#') {
      visited[x+1][y] = 1;
      dfs(x+1, y, length + 1);
      visited[x+1][y] = 0;
    } 
  }
  if (y - 1 >= 0) {
    if (visited[x][y-1] == 0 && maze[x][y-1] != '#') {
      visited[x][y-1] = 1;
      dfs(x, y-1, length + 1);
      visited[x][y-1] = 0;
    }
  }
  if (x - 1 >= 0) {
    if (visited[x-1][y] == 0 && maze[x-1][y] != '#') {
      visited[x-1][y] = 1;
      dfs(x-1, y, length + 1);
      visited[x-1][y] = 0;
    }
  }
}

int main() {
  cin >> K;
  int a, b;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      maze[i][j] = '.';
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    maze[a-1][b-1] = '#';
  }
  visited[0][0] = 1;
  dfs(0,0,0);
  cout << ans << endl;
}