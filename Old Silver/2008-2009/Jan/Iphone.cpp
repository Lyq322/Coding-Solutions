#include <iostream>
#include <queue>

using namespace std;

int W, H;
char map[100][100];
int visited[100][100] = {{0}};
int S_x, S_y;
int found = false;
queue<pair<pair<int, int>, int>> bfs;

int main() {
  cin >> H >> W;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'C' && !found) {
        S_x = i;
        S_y = j;
        visited[i][j] = 1;
        found = true;
      }
    }
  }
  found = false;
  for (int i = S_x + 1; i < W; i++) {
    if (map[i][S_y] == '*') {
      break;
    }
    else if (map[i][S_y] == 'C') {
      found = true;
      break;
    }
    visited[i][S_y] = 1;
    bfs.push({{i, S_y}, 0});
  }
  for (int i = S_x - 1; i >= 0; i--) {
    if (map[i][S_y] == '*') {
      break;
    }
    else if (map[i][S_y] == 'C') {
      found = true;
      break;
    }
    visited[i][S_y] = 1;
    bfs.push({{i, S_y}, 0});
  }
  for (int i = S_y + 1; i < H; i++) {
    if (map[S_x][i] == '*') {
      break;
    }
    else if (map[S_x][i] == 'C') {
      found = true;
      break;
    }
    visited[S_x][i] = 1;
    bfs.push({{S_x, i}, 0});
  }
  for (int i = S_y - 1; i >= 0; i--) {
    if (map[S_x][i] == '*') {
      break;
    }
    else if (map[S_x][i] == 'C') {
      found = true;
      break;
    }
    visited[S_x][i] = 1;
    bfs.push({{S_x, i}, 0});
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  if (found) {
    cout << 0 << endl;
  }
  else {
    while (!bfs.empty()) {
      //cin.ignore();
      pair<int, int> pos = bfs.front().first;
      //cout << "x " << pos.first << " y " << pos.second << endl;
      int moves = bfs.front().second;
      if (moves == 0) {
        cout << pos.first << ' ' << pos.second << endl;
      }
      if (map[pos.first][pos.second] == 'C') {
        cout << moves << endl;
        break;
      }
      bfs.pop();
      for (int i = pos.first + 1; i < W; i++) {
        if (map[i][pos.second] == '*') {
          break;
        }
        if (visited[i][pos.second] == 0) {
          visited[i][pos.second] = moves + 1;
          bfs.push({{i, pos.second}, moves + 1});
        }
      }
      for (int i = pos.first - 1; i >= 0; i--) {
        if (map[i][pos.second] == '*') {
          break;
        }
        if (visited[i][pos.second] == 0) {
          visited[i][pos.second] = moves + 1;
          bfs.push({{i, pos.second}, moves + 1});
        }
      }
      for (int i = pos.second + 1; i < H; i++) {
        if (map[pos.first][i] == '*') {
          break;
        }
        if (visited[pos.first][i] == 0) {
          visited[pos.first][i] = moves + 1;
          bfs.push({{pos.first, i}, moves + 1});
        }
      }
      for (int i = pos.second - 1; i >= 0; i--) {
        if (map[pos.first][i] == '*') {
          break;
        }
        if (visited[pos.first][i] == 0) {
          visited[pos.first][i] = moves + 1;
          bfs.push({{pos.first, i}, moves + 1});
        }
      }
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}