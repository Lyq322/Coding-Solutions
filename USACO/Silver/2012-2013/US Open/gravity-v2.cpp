#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char grid[500][500];
bool visited[500][500][4] = {{{0}}};
int sx, sy;
int di[8] = {0, 1, 0, 1, 0, -1, 0, -1};
int dj[8] = {1, 0, 1, 0, -1, 0, -1, 0};
bool found = false;

pii landing(pii pos, int dir, int moves) {
  pii haybale = {-1, -1};
  if (dir == 0) {
      for (int i = pos.first; i < N; i++) {
        if (grid[i][pos.second] == 'D') {
          found = true;
          cout << moves << endl;
          return {-2, -2};
        }
        if (grid[i][pos.second] == '#') {
          haybale = {i - 1, pos.second};
          break;
        }
      }
    }
    else {
      for (int i = pos.first; i > -1; i--) {
        if (grid[i][pos.second] == 'D') {
          found = true;
          cout << moves << endl;
          return {-2, -2};
        }
        if (grid[i][pos.second] == '#') {
          haybale = {i + 1, pos.second};
          break;
        }
      }
    }
  return haybale;
}

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
  queue<pair<pii, pii>> zero_q;
  queue<pair<pii, pii>> one_q;
  zero_q.push({{sx, sy}, {0, 0}});
  while (!zero_q.empty() || !one_q.empty()) {
    while (!zero_q.empty()) {
      pii pos = zero_q.front().first;
      int dir = zero_q.front().second.first;
      int moves = zero_q.front().second.second;
      zero_q.pop();
      
      pii land = landing(pos, dir, moves);
      if (found) break;
      if (land.first == -1) {
        continue;
      }
      if (!visited[land.first][land.second][dir]) {
        visited[land.first][land.second][dir] = true;
        for (int i = 0; i < 4; i = i + 2) {
          if (i != dir) {
            one_q.push({land, {i, moves + 1}});
          }
        }
        if (grid[land.first + di[dir]][land.second + dj[dir]] != '#') {
          zero_q.push({{land.first + di[dir], land.second + dj[dir]}, {dir, moves}});
        }
        if (grid[land.first + di[dir + 4]][land.second + dj[dir + 4]] != '#') {
          zero_q.push({{land.first + di[dir + 4], land.second + dj[dir + 4]}, {dir, moves}});
        }
      }
    }
    if (found) break;
    while (!one_q.empty()) {
      zero_q.push(one_q.front());
      one_q.pop();
    }
  }
  if (!found) {
    cout << -1 << endl;
  }
}