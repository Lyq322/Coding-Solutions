#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int sx, sy;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int grid[1001][1001] = {{0}};
bool visited[1001][1001] = {{0}};

int main() {
  cin >> N >> sx >> sy;
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    grid[a][b] = 1;
  }
  queue<pair<pii, int>> q1;
  queue<pair<pii, int>> q2;
  q1.push({{0, 0}, 0});
  visited[0][0] = true;
  bool found = false;
  while (!found) {
    while (!q1.empty()) {
      pii pos = q1.front().first;
      int dist = q1.front().second;
      q1.pop();
      if (pos.first == sx && pos.second == sy) {
        cout << dist << endl;
        found = true;
        break;
      }
      for (int i = 0; i < 4; i++) {
        int a = di[i] + pos.first;
        int b = dj[i] + pos.second;
        if (a >= 0 && b >= 0 && a <= 1000 && b <= 1000 && !visited[a][b]) {
          visited[a][b] = true;
          if (grid[a][b] == 1) {
            q2.push({{a, b}, dist + 1});
          }
          else {
            q1.push({{a, b}, dist});
          }
        }
      }
    }
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }
}