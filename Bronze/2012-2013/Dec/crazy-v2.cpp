#include <iostream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

struct Point{
  int x;
  int y;
};

int N, C;
Point all[1500];
int x1[500];
int x2[500];
int y1[500];
int y2[500];
int Cx[500];
int Cy[500];
map<int, int> mapx;
map<int, int> mapy;
stack<int> row;
stack<int> col;
int a[3000][3000] = {{0}};
int visited[3000][3000] = {{0}};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int c;
int ans = 0;

bool comp1 (Point a, Point b) {
  return a.x < b.x;
}

bool comp2 (Point a, Point b) {
  return a.y < b.y;
}

int main() {
  cin >> N >> C;
  int index = 0;
  for (int i = 0; i < N; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    all[index] = {x1[i], y1[i]};
    index++;
    all[index] = {x2[i], y2[i]};
    index++;
  }
  for (int i = 0; i < C; i++) {
    cin >> Cx[i] >> Cy[i];
    all[index] = {Cx[i], Cy[i]};
    index++;
  }
  sort(all, all + index, comp1);
  int counter = 0;
  for (int i = 0; i < index; i++) {
    if (mapx.find(all[index].x) != mapx.end()) {
      mapx[all[index].x] = counter;
      counter += 2;
    }
  }
  int max_x = counter;
  sort(all, all + index, comp2);
  counter = 0;
  for (int i = 0; i < index; i++) {
    if (mapy.find(all[index].y) != mapy.end()) {
      mapy[all[index].y] = counter;
      counter += 2;
    }
  }
  int max_y = counter;
  for (int i = 0; i < N; i++) {
    if (y1[i] == y2[i]) {
      for (int j = min(mapx[x1[i]], mapx[x2[i]]); j < max(mapx[x1[i]], mapx[x2[i]]); j++) {
        a[mapy[y1[i]]][j] = 1;
      }
    }
    else {
      for (int j = min(mapy[y1[i]], mapy[y2[i]]); j < max(mapy[y1[i]], mapy[y2[i]]); j++) {
        a[j][mapx[x1[i]]] = 1;
      }
    }
  }
  for (int i = 0; i < C; i++) {
    a[mapy[Cy[i]]][mapx[Cx[i]]] = 2;
  }
  for (int i = 0; i <= max_x; i++) {
    for (int j = 0; j <= max_y; j++) {
      cout << a[i][j] << endl;
    }
  }
  for (int i = 0; i <= max_x; i++) {
    for (int j = 0; j <= max_y; j++) {
      if (visited[i][j] == 0 && a[i][j] != 1) {
        row.push(i);
        col.push(j);
        c = 0;
        while (!row.empty()) {
          int cur_x = row.top();
          int cur_y = col.top();
          row.pop();
          col.pop();
          if (a[cur_x][cur_y] == 2) {
            c++;
          }
          for (int i = 0; i < 4; i++) {
            int xx = cur_x + di[i];
            int yy = cur_y + dj[i];
            if (xx >= 0 && yy >= 0 && xx <= max_x && yy <= max_y && visited[xx][yy] == 0 && a[xx][yy] != 1) {
              visited[xx][yy] = 1;
              row.push(xx);
              col.push(yy);
            }
          }
        }
        ans = max(ans, c);
      }
    }
  }
  cout << ans << endl;
}