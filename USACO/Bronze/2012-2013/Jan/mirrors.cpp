#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n;

struct mirror {
  int x, y;
  char type;
};

int mirror_x[202] = {0};
int mirror_y[202] = {0};
map<int, int> x_coord;
map<int, int> y_coord;
mirror mirrors[200];
char grid[200][200];
int visited[200][200] = {{0}};
int sx, sy, fx, fy;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
bool found = false;
bool ans = false;

// 0 - Right
// 1 - Down
// 2 - Left
// 3 - Up
void check(int pos_x, int pos_y, int dir) {
  if (found) {
    return;
  }
  int a = pos_x + di[dir];
  int b = pos_y + dj[dir];
  if (a >= 0 && b >= 0 && a < 200 && b < 200 && visited[a][b] < 2) {
    visited[a][b]++;
    if (grid[a][b] == '.' || grid[a][b] == 'H') {
      check(a, b, dir);
    }
    else if (grid[a][b] == '/') {
      if (dir == 3) {
        dir = 0;
      }
      else if (dir == 2) {
        dir = 1;
      }
      else if (dir == 1) {
        dir = 2;
      }
      else {
        dir = 3;
      }
      check(a, b, dir);
    }
    else if (grid[a][b] == '\\') {
      if (dir == 3) {
        dir = 2;
      }
      else if (dir == 2) {
        dir = 3;
      }
      else if (dir == 1) {
        dir = 0;
      }
      else {
        dir = 1;
      }
      check(a, b, dir);
    }
    else if (grid[a][b] == 'B') {
      found = true;
      return;
    }
  }
}

int main() {
  cin >> n >> fx >> fy;
  char c;
  for (int i = 1; i <= n; i++) {
    cin >> mirror_x[i] >> mirror_y[i] >> c;
    if (c == '\\') {
      c = '/';
    }
    else {
      c = '\\';
    }
    mirrors[i - 1] = {mirror_x[i], mirror_y[i], c};
  }
  mirror_x[0] = fx;
  mirror_y[0] = fy;
  mirror_x[201] = 0;
  mirror_y[201] = 0;
  sort(mirror_x, mirror_x + 202);
  int new_coord = 0;
  for (int i = 0; i < 202; i++) {
    if (!x_coord.count(mirror_x[i])) {
      x_coord[mirror_x[i]] = new_coord;
      new_coord++;
    }
  }
  sort(mirror_y, mirror_y + 202);
  new_coord = 0;
  for (int i = 0; i < 202; i++) {
    if (!y_coord.count(mirror_y[i])) {
      y_coord[mirror_y[i]] = new_coord;
      new_coord++;
    }
  }
  for (int i = 0; i < n; i++) {
    mirrors[i].x = x_coord[mirrors[i].x];
    mirrors[i].y = y_coord[mirrors[i].y];
  }
  fx = x_coord[fx];
  fy = y_coord[fy];
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      grid[i][j] = '.';
    }
  }
  for (int i = 0; i < n; i++) {
    grid[mirrors[i].x][mirrors[i].y] = mirrors[i].type;
  }
  sx = x_coord[0];
  sy = y_coord[0];
  grid[sx][sy] = 'H';
  grid[fx][fy] = 'B';
  found = false;
  check(sx, sy, 1);
  if (found) {
    cout << 0 << endl;
    ans = true;
  }
  else {
    for (int i = 0; i < n; i++) {
      found = false;
      for (int j = 0; j < 200; j++) {
        for (int k = 0; k < 200; k++) {
          visited[j][k] = false;
        }
      }
      if (grid[mirrors[i].x][mirrors[i].y] == '/') {
        grid[mirrors[i].x][mirrors[i].y] = '\\';
      }
      else {
        grid[mirrors[i].x][mirrors[i].y] = '/';
      }
      check(sx, sy, 1);
      if (grid[mirrors[i].x][mirrors[i].y] == '/') {
        grid[mirrors[i].x][mirrors[i].y] = '\\';
      }
      else {
        grid[mirrors[i].x][mirrors[i].y] = '/';
      }
      if (found) {
        cout << i + 1 << endl;
        ans = true;
        break;
      }
    }
  }
  if (!ans) {
    cout << -1 << endl;
  }
} 