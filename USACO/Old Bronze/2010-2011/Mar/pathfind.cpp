#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int matrix[100][100];
queue<pii> bfs;
int visited[100] = {0};

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }
  bfs.push({M, 1});
  visited[M-1] = 1;
  int pos, time;
  while (!bfs.empty()) {
    pos = bfs.front().first;
    time = bfs.front().second;
    bfs.pop();
    for (int i = 0; i < N; i++) {
      if (matrix[pos - 1][i] == 1 && visited[i] == 0) {
        bfs.push({i + 1, time + 1});
        visited[i] = time + 1;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << visited[i] << ' ';
  }
  cout << endl;
  for (int i = 1; i < time + 1; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[j] == i) {
        cout << j + 1 << ' ';
      }
    }
    cout << endl;
  }
}