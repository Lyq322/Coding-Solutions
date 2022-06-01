#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pii;

struct Point {
  int x;
  int y;
  int m;
};

int N, M;
char grid[300][300];
int visited[300][300] = {{0}};
queue<Point> bfs;
map<pii, pii> teleport;
map<char, pii> t;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '@') {
        bfs.push({i, j, 0});
        visited[i][j] = 2;
      }
      else if (grid[i][j] <= 'Z' && 'A' <= grid[i][j]) {
        if (t.find(grid[i][j]) == t.end()) {
          t[grid[i][j]] = {i, j};
        }
        else {
          teleport[{i, j}] = t[grid[i][j]];
          teleport[t[grid[i][j]]] = {i, j};
          //cout << "(" << i << ',' << j << ")" << ' ' << '(' << t[grid[i][j]].first << ',' << t[grid[i][j]].second << ')' << endl; 
        }
      }
    }
  }
  int a, b, moves;
  while (!bfs.empty()) {
    a = bfs.front().x;
    b = bfs.front().y;
    moves = bfs.front().m;
    bfs.pop();
    if (grid[a][b] == '=') {
      cout << moves << endl;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int c = a + di[i];
      int d = b + dj[i];
      if (c >= 0 && d >= 0 && c < N && d < M && visited[c][d] != 2 && grid[c][d] != '#') {
        if (grid[c][d] == '.' || grid[c][d] == '=') {
          bfs.push({c, d, moves + 1});
          visited[c][d] = 2;
        }
        else {
          if (teleport.find({c, d}) == teleport.end()) {
            continue;
          }
          pii p = teleport[{c, d}];
          bfs.push({p.first, p.second, moves + 1});
          teleport.erase({c, d});
        }
      }
    }
  }
}