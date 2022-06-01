#include <iostream>

using namespace std;

int n;
string maze[25][25];
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
bool visited[25][25][19683];
char current[3][3];

int cal() {
  int total = 0;
  int index = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (current[i][j] == 'M') {
        total += index;
      }
      else if (current[i][j] == 'O') {
        total += index * 2;
      }
      index *= 3;
    }
  }
  return total;
}

int reverse_cal() {
  
}

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int a = di[i] + x;
    int b = dj[i] + y;
    if (a >= 0 && b >= 0 && a < n && b < n && maze[a][b] != "###") {
      if (maze[a][b] != "..." && maze[a][b] != "BBB") {
        int pos1 = maze[a][b].at(1) - '0' - 1;
        int pos2 = maze[a][b].at(2) - '0' - 1;
        if (current[pos1][pos2] == ' ') {
          current[pos1][pos2] = maze[a][b].at(0);
          int t = cal();
          if (!visited[a][b][t]) {
            visited[a][b][t] = true;
            dfs(a, b);
          }
          current[pos1][pos2] = ' ';
        }
        else {
          int t = cal();
          if (!visited[a][b][t]) {
            visited[a][b][t] = true;
            dfs(a, b);
          }
        }
      }
      else {
        int t = cal();
        if (!visited[a][b][t]) {
          visited[a][b][t] = true;
          dfs(a, b);
        }
      }
    }
  }
}

int main() {
  cin >> n;
  int sx, sy;
  string s;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      s = "";
      for (int k = 0; k < 3; k++) {
        cin >> c;
        s += c;
      }
      maze[i][j] = s;
      if (maze[i][j] == "BBB") {
        sx = i;
        sy = j;
      } 
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      current[i][j] = ' ';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 19683; k++) {
        visited[i][j][k] = false;
      }
    }
  }
  visited[sx][sy][0] = true;
  dfs(sx, sy);
  cout << "hi\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 19683; k++) {
        if (visited[i][j][k]) {
          cout << i << j << k << endl;
        }
      }
    }
  }
}