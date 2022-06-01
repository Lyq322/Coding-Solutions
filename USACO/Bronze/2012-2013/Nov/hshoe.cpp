#include <iostream>

using namespace std;

int N;
char** grid;
int** visited;
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
int best = 0;

void dfs(int x, int y, int open, int close) {
  if (open == close) {
    if (best < open + close) {
      best = open * 2;
    }
  }
  //cout << "x " << x << " y " << y << endl;
  //cout << open << ' ' << close << endl;
  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }*/
  //cin.ignore();
  for (int i = 0; i < 4; i++) {
    int a = x + di[i];
    int b = y + dj[i];
    if (a >= 0 && b >= 0 && a < N && b < N && visited[a][b] == 0) {
      if (grid[x][y] == '(' && grid[a][b] == '(') {
        visited[a][b] = open + close + 1;
        dfs(a, b, open + 1, close);
      }
      else if (grid[x][y] == '(' && grid[a][b] == ')') {
        visited[a][b] = open + close + 1;
        dfs(a, b, open, close + 1);
      }
      else if (grid[x][y] == ')' && grid[a][b] == ')') {
        visited[a][b] = open + close + 1;
        dfs(a, b, open, close + 1);
      }
      visited[a][b] = 0;
    }
  }
}

int main() {
  cin >> N;
  grid = new char*[N];
  visited = new int*[N];
  for (int i = 0; i < N; i++) {
    grid[i] = new char[N];
    visited[i] = new int[N];
    for (int j = 0; j < N; j++) {
      visited[i][j] = 0;
      cin >> grid[i][j];
    }
  }
  if (grid[0][0] == '(') {
    visited[0][0] = 1;
    dfs(0, 0, 1, 0);
  }
  else {
    best = 0;
  }
  cout << best << endl;
}