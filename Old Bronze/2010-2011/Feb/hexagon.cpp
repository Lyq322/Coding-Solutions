#include <iostream>
#include <queue>
#include <set>

using namespace std;

int k, h, l;
int grid[100][200] = {{0}};
int di[6] = {0, 1, 1, 0, -1, -1};
int dj[6] = {2, 1, -1, -2, -1, 1};
set<int> ans;
int visited[100][200] = {{0}};
int start_x, start_y;

void bfs(int c, int d) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{start_x, start_y}, 0});
  while (!q.empty()) {
    int depth = q.front().second;
    pair<int, int> pos = q.front().first;
    q.pop();
    cout << pos.first << ' ' << pos.second << endl;
    if (depth == l) {
      ans.insert(grid[pos.first][pos.second]);
      visited[pos.first][pos.second] = 1;
      continue;
    }
    int a = di[c] + pos.first;
    int b = dj[c] + pos.second;
    if (a >= 0 && b >= 0 && a < 2 * k - 1 && b < 4 * k - 3 && depth <= l && grid[a][b] != 0 && visited[a][b] == 0) {
      q.push({{a, b}, depth + 1});
      visited[a][b] = 1;
    }
    a = di[d] + pos.first;
    b = dj[d] + pos.second;
    if (a >= 0 && b >= 0 && a < 2 * k - 1 && b < 4 * k - 3 && depth <= l && grid[a][b] != 0 && visited[a][b] == 0) {
      q.push({{a, b}, depth + 1});
      visited[a][b] = 1;
    }
  }
}
int main() {
  cin >> k >> h >> l;
  int start = k - 1;
  int t = k;
  int index = 1;
  for (int i = 0; i < 2 * k - 1; i++) {
    for (int j = 0; j < t; j++) {
      int pos = start + 2 * j;
      grid[i][pos] = index;
      if (index == h) {
        start_x = i;
        start_y = pos;
      }
      index++;
    }
    if (i < k - 1) {
      start--;
      t++;
    }
    else {
      start++;
      t--;
    }
  }
  for (int a = 0; a < 6; a++) {
    for (int i = 0; i < 2 * k - 1; i++) {
      for (int j = 0; j < 4 * k - 3; j++) {
        visited[i][j] = 0;
      }
    }
    bfs(a, (a + 1) % 6);
  }
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << endl;
  }
} 


/*#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int k, h, l;
int grid[100][200] = {{0}};
int di[6] = {0, 1, 1, 0, -1, -1};
int dj[6] = {2, 1, -1, -2, -1, 1};
int visited[100][200] = {{0}};
vector<int> ans;
int start_x, start_y;

void bfs(int c, int d) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{start_x, start_y}, 0});
  while (!q.empty()) {
    int depth = q.front().second;
    pair<int, int> pos = q.front().first;
    q.pop();
    cout << grid[pos.first][pos.second] << ' ' << depth << endl;
    if (depth == l) {
      ans.push_back(grid[pos.first][pos.second]);
    }
    int a = di[c] + pos.first;
    int b = dj[c] + pos.second;
    if (a >= 0 && b >= 0 && a < 2 * k - 1 && b < 4 * k - 3 && depth <= l && grid[a][b] != 0 && visited[a][b] == 0) {
      visited[a][b] = 1;
      q.push({{a, b}, depth + 1});
    }
    a = di[d] + pos.first;
    b = dj[d] + pos.second;
    if (a >= 0 && b >= 0 && a < 2 * k - 1 && b < 4 * k - 3 && depth <= l && grid[a][b] != 0 && visited[a][b] == 0) {
      visited[a][b] = 1;
      q.push({{a, b}, depth + 1});
    }
  }
}
int main() {
  cin >> k >> h >> l;
  int start = k - 1;
  int t = k;
  int index = 1;
  for (int i = 0; i < 2 * k - 1; i++) {
    for (int j = 0; j < t; j++) {
      int pos = start + 2 * j;
      grid[i][pos] = index;
      if (index == h) {
        start_x = i;
        start_y = pos;
      }
      index++;
    }
    if (i < k - 1) {
      start--;
      t++;
    }
    else {
      start++;
      t--;
    }
  }
  for (int i = 0; i < 2 * k - 1; i++) {
    for (int j = 0; j < 4 * k - 3; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
  //bfs(5, 0);
  for (int i = 0; i < 6; i++) {
    cout << i << ' ' << (i + 1) % 6 << endl;
    bfs(i, (i + 1) % 6);
  }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
} */