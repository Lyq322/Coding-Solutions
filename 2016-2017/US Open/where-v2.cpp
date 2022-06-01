#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
char grid[20][20];
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

bool check(int r, int c, int rLen, int cLen) {
  bool visited[20][20] = {{0}};
  char firstColor;
  int firstCount = 0;
  char secondColor;
  int secondCount = 0;
  for (int i = r; i < r + rLen; i++) {
    for (int j = c; j < c + cLen; j++) {
      if (!visited[i][j]) {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int a = x + di[k];
            int b = y + dj[k];
            if (a >= r && b >= c && a < r + rLen && b < c + cLen && !visited[a][b] && grid[a][b] == grid[i][j]) {
              visited[a][b] = true;
              q.push({a, b});
            }
          }
        }
        if (firstCount == 0 || firstColor == grid[i][j]) {
          firstCount++;
          firstColor = grid[i][j];
        }
        else if (secondCount == 0 || secondColor == grid[i][j]) {
          secondCount++;
          secondColor = grid[i][j];
        }
        else {
          return false;
        }
      }
    }
  }
  if (firstCount == 1 && secondCount >= 2) {
    cout << "first " << firstColor << ' ' << firstCount << endl;
    cout << "second " << secondColor << ' ' << secondCount << endl;
    return true;
  }
  else if (firstCount >= 2 && secondCount == 1) {
    cout << "first " << firstColor << ' ' << firstCount << endl;
    cout << "second " << secondColor << ' ' << secondCount << endl;
    return true;
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  vector<pair<pair<int, int>, pair<int, int>>> pcl;
  for (int rLen = n; rLen > 0; rLen--) {
    for (int cLen = n; cLen > 0; cLen--) {
      for (int r = 0; r <= n - rLen; r++) {
        for (int c = 0; c <= n - cLen; c++) {
          if (check(r, c, rLen, cLen)) {
            cout << "work " << r << ' ' << c << ' ' << rLen << ' ' << cLen << endl;
            pcl.push_back({{r, c}, {rLen, cLen}});
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < pcl.size(); i++) {
    bool biggest = true;
    for (int j = 0; j < pcl.size(); j++) {
      if (i != j && pcl[j].first.first <= pcl[i].first.first && pcl[j].first.second <= pcl[i].first.second && pcl[j].second.first + pcl[j].first.first >= pcl[i].second.first + pcl[i].first.first && pcl[j].second.second + pcl[j].first.second >= pcl[i].second.second + pcl[i].first.second) {
        biggest = false;
        break;
      }
    }
    if (biggest) {
      for (int k = pcl[i].first.first; k < pcl[i].first.first + pcl[i].second.first; k++) {
        for (int l = pcl[i].first.second; l < pcl[i].first.second + pcl[i].second.second; l++) {
          cout << grid[k][l] << ' ';
        }
        cout << endl;
      }
      ans++;
    }
  }
  cout << ans << endl;
}