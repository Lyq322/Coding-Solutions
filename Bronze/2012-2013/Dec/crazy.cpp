#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
  int x;
  int y;
  int p1;
  int p2;
};

typedef pair<int, int> pii;

int N, C;
pii fences[500][2];
pii cows[500];
Point points[1500];
int grid[1500][1500] = {{0}};
int visited[1500][1500] = {{0}};
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int max_x, max_y;
int c;
int ans = 0;

bool comp_x(Point a, Point b) {
  return a.x < b.x;
}

bool comp_y(Point a, Point b) {
  return a.y < b.y;
}

int main() {
  cin >> N >> C;
  int x1, y1, x2, y2;
  int index = 0;
  for (int i = 0; i < N; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    fences[i][0] = {x1, y1};
    fences[i][1] = {x2, y2};
    points[index] = {x1, y1, i, 0};
    points[index + 1] = {x2, y2, i, 1};
    index += 2;
  }
  for (int i = 0; i < C; i++) {
    cin >> x1 >> y1;
    cows[i] = {x1, y1};
    points[index] = {x1, y1, i, -1};
    index++;
  }
  sort(points, points + 2 * N + C, comp_x);
  int pos = 0;
  int previous = -1;
  for (int i = 0; i < 2*N + C; i++) {
    if (previous == -1 || points[i].x == previous) {
      if (points[i].p2 == -1) {
        cows[points[i].p1].first = pos;
      }
      else {
        fences[points[i].p1][points[i].p2].first = pos;
      }
      previous = points[i].x;
    }
    else {
      pos += 2;
      if (points[i].p2 == -1) {
        cows[points[i].p1].first = pos;
      }
      else {
        fences[points[i].p1][points[i].p2].first = pos;
      }
      previous = points[i].x;
    }
  }
  max_x = pos;
  sort(points, points + 2 * N + C, comp_y);
  pos = 0;
  previous = -1;
  for (int i = 0; i < 2*N + C; i++) {
    if (previous == -1 || points[i].y == previous) {
      if (points[i].p2 == -1) {
        cows[points[i].p1].second = pos;
      }
      else {
        fences[points[i].p1][points[i].p2].second = pos;
      }
      previous = points[i].y;
    }
    else {
      pos += 2;
      if (points[i].p2 == -1) {
        cows[points[i].p1].second = pos;
      }
      else {
        fences[points[i].p1][points[i].p2].second = pos;
      }
      previous = points[i].y;
    }
  }
  max_y = pos;
  for (int i = 0; i < N; i++) {
    if (fences[i][0].first == fences[i][1].first) {
      for (int j = min(fences[i][0].second, fences[i][1].second); j <= max(fences[i][0].second, fences[i][1].second); j++) {
        grid[fences[i][0].first][j] = 1;
      }
    }
    else {
      for (int j = min(fences[i][0].first, fences[i][1].first); j <= max(fences[i][0].first, fences[i][1].first); j++) {
        grid[j][fences[i][0].second] = 1;
      }
    }
  }
  for (int i = 0; i < C; i++) {
    grid[cows[i].first][cows[i].second] = 2;
  }
  cout << "tuna\n";
  for (int i = 0; i <= max_x; i++) {
    for (int j = 0; j <= max_y; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  stack<int> row;
  stack<int> col;
  int a, b, x, y;
  for (int i = 0; i < C; i++) {
    c = 0;
    if (visited[cows[i].first][cows[i].second] == 1) {
      continue;
    }
    row.push(cows[i].first);
    col.push(cows[i].second);
    while (!row.empty()) {
      x = row.top();
      y = col.top();
      cout << "x " << x << " y " << y << endl;
      for (int k = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
          cout << visited[k][j];
        }
        cout << endl;
      }
      row.pop();
      col.pop();
      if (grid[x][y] == 2) {
        c++;
      }
      for (int i = 0; i < 4; i++) {
        a = x + di[i];
        b = y + dj[i];
        cout << "a " << a << " b " << b << endl;
        if (a >= 0 && b >= 0 && a <= max_x && b <= max_y && visited[a][b] == 0 && grid[a][b] != 1) {
          cout << "hi\n";
          row.push(a);
          col.push(b);
          visited[a][b] = 1;
        }
      }
    }
    cout << endl;
    ans = max(ans, c);
  }
  cout << ans << endl;
}