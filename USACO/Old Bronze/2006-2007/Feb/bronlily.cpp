#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int M, N, M1, M2;
int pond[30][30];
queue<pair<pii, int>> bfs;
int visited[30][30] = {{0}};
pii start, finish;
int di[4] = {1, 1, -1, -1};
int dj[4] = {1, -1, 1, -1};

int main() {
  cin >> M >> N >> M1 >> M2;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> pond[i][j];
      if (pond[i][j] == 3) {
        start = {i, j};
      }
      else if (pond[i][j] == 4) {
        finish = {i, j};
      }
    }
  }
  bfs.push({start, 0});
  visited[start.first][start.second] = 1;
  pii pos;
  int moves;
  while (!bfs.empty()) {
    pos = bfs.front().first;
    moves = bfs.front().second;
    bfs.pop();
    if (pos == finish) {
      cout << moves << endl;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int x1 = pos.first + dj[i] * M2;
      int y1 = pos.second + di[i] * M1;
      int x2 = pos.first + dj[i] * M1;
      int y2 = pos.second + di[i] * M2;
      if (x1 >= 0 && y1 >= 0 && x1 < M && y1 < N && pond[x1][y1] != 0 && pond[x1][y1] != 2 && visited[x1][y1] == 0) {
        bfs.push({{x1, y1}, moves + 1});
        visited[x1][y1] = 1;
      }
      if (x2 >= 0 && y2 >= 0 && x2 < M && y2 < N && pond[x2][y2] != 0 && pond[x2][y2] != 2 && visited[x2][y2] == 0) {
        bfs.push({{x2, y2}, moves + 1});
        visited[x2][y2] = 1;
      }
    }
  }
}