#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

int N, K;
int grid[100][100];
int di[4] = {0, 1, -1, 0};
int dj[4] = {1, 0, 0, -1};

void moveDown() {
  for (int i = 0; i < 10; i++) {
    int temp[100];
    int index = 0;
    for (int j = 0; j < N; j++) {
      if (grid[j][i] != 0) {
        temp[index] = grid[j][i];
        index++;
      }
    }
    for (int j = 0; j < N; j++) {
      grid[j][i] = 0;
    }
    for (int j = 0; j < index; j++) {
      grid[N - j - 1][i] = temp[index - j - 1];
    }
  }
}

int checkConsecutive() {
  bool visited[100][100] = {{0}};
  bool changed = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      if (!visited[i][j] && grid[i][j] != 0) {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        vector<pair<int, int>> points;
        points.push_back({i, j});
        q.push({i, j});
        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int a = x + di[k];
            int b = y + dj[k];
            if (a >= 0 && b >= 0 && a < N && b < 10 && !visited[a][b] &&
                grid[a][b] == grid[i][j]) {
              visited[a][b] = true;
              points.push_back({a, b});
              q.push({a, b});
            }
          }
        }
        if (points.size() >= K) {
          changed = true;
          for (int k = 0; k < points.size(); k++) {
            grid[points[k].first][points[k].second] = 0;
          }
        }
      }
    }
  }
  return changed;
}

int main() {
  fin.open("mooyo.in");
  fout.open("mooyo.out");
  fin >> N >> K;
  string s;
  for (int i = 0; i < N; i++) {
    fin >> s;
    for (int j = 0; j < 10; j++) {
      char character = s.at(j);
      int num = character - '0';
      grid[i][j] = num;
    }
  }
  while (checkConsecutive()) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 10; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
    moveDown();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 10; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
}