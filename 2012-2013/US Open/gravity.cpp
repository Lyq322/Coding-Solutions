#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char grid[500][500];
int sx, sy;
int visited[500][500] = {{0}};
int di[8] = {0, 1, 0, 1, 0, -1, 0, -1};
int dj[8] = {1, 0, 1, 0, -1, 0, -1, 0};

/*
0 - down
1 - left
2 - up
3 - right
*/

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'C') {
        sx = i;
        sy = j;
      }
    }
  }
  queue<pair<pii, pii>> q;
  q.push({{sx, sy}, {0, 0}});
  while (!q.empty()) {
    pii pos = q.front().first;
    int dir = q.front().second.first;
    int moves = q.front().second.second;
    q.pop();

    cout << pos.first << ' ' << pos.second << ' ' << dir << ' ' << moves << endl;
    
    pii haybale = {-1, -1};
    if (dir == 3) {
      for (int i = pos.second + 1; i < M; i++) {
        if (grid[pos.first][i] == 'D') {
          cout << "moves " << moves << endl;
          break;
        }
        else if (grid[pos.first][i] == '#') {
          haybale = {pos.first, i - 1};
        }
      }
      if (haybale.first == -1) {
        cout << "nothing\n";
        continue;
      }
    }
    else if (dir == 0) {
      for (int i = pos.first + 1; i < N; i++) {
        if (grid[i][pos.second] == 'D') {
          cout << "moves " << moves << endl;
          break;
        }
        else if (grid[i][pos.second] == '#') {
          haybale = {i - 1, pos.second};
        }
      }
      if (haybale.first == -1) {
        cout << "nothing\n";
        continue;
      }
    }
    else if (dir == 1) {
      for (int i = pos.second - 1; i > -1; i--) {
        if (grid[pos.first][i] == 'D') {
          cout << "moves " << moves << endl;
          break;
        }
        else if (grid[pos.first][i] == '#') {
          haybale = {pos.first, i + 1};
        }
      }
      if (haybale.first == -1) {
        cout << "nothing\n";
        continue;
      }
    }
    else {
      for (int i = pos.first - 1; i > -1; i--) {
        if (grid[i][pos.second] == 'D') {
          cout << "moves " << moves << endl;
          break;
        }
        else if (grid[i][pos.second] == '#') {
          haybale = {i + 1, pos.second};
        }
      }
      if (haybale.first == -1) {
        cout << "nothing\n";
        continue;
      }
    }
    if (visited[haybale.first][haybale.second] == 0) {
      cout << haybale.first << ' ' << haybale.second << endl;
      visited[haybale.first][haybale.second] = moves + 1;
      for (int i = 0; i < 4; i++) {
        if (i != dir) {
          q.push({haybale, {i, moves + 1}});
        }
      }
      if (grid[haybale.first + di[dir]][haybale.second + dj[dir]] != '#') {
        q.push({{haybale.first + di[dir], haybale.second + dj[dir]}, {dir, moves}});
      }
      if (grid[haybale.first + di[dir + 4]][haybale.second + dj[dir + 4]] != '#') {
        q.push({{haybale.first + di[dir + 4], haybale.second + dj[dir + 4]}, {dir, moves}});
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << endl;
  }
}