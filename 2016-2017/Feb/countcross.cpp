#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, R;
bool visited[200][200] = {{0}};
int grid[200][200];
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
  cin >> N >> K >> R;
  int a, b, c, d;
  for (int i = 0; i < R; i++) {
    cin >> a >> b >> c >> d;
    if (a == c) {
      grid[2 * a - 2][2 * min(b, d) - 1] = -1;
    }
    else {
      grid[2 * min(a, c) - 1][2 * b - 2] = -1;
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      grid[2 * i + 1][2 * j + 1] = -1;
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    grid[2 * a - 2][2 * b - 2] = 1;
  }
  vector<int> v;
  for (int i = 0; i < 2 * N - 1; i++) {
    for (int j = 0; j < 2 * N - 1; j++) {
      if (!visited[i][j] && grid[i][j] != -1) {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int count = 0;
        if (grid[i][j] == 1) {
          count++;
        }
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int a = x + di[k];
            int b = y + dj[k];
            if (a >= 0 && b >= 0 && a < 2 * N - 1 && b < 2 * N - 1 && grid[a][b] != -1 && !visited[a][b]) {
              visited[a][b] = true;
              q.push({a, b});
              if (grid[a][b] == 1) {
                count++;
              }
            }
          }
        }
        v.push_back(count);
      }
    }
  }
  int total = 0;
  int ps = 0;
  for (int i = 0; i < v.size(); i++) {
    total += ps * v[i];
    ps += v[i];
  }
  cout << total << endl;
}