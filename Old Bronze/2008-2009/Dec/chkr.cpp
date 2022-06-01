#include <iostream>
#include <vector>

using namespace std;

int n;
char grid[30][30];
int opponent = 0;
int di[4] = {1, 1, -1, -1};
int dj[4] = {1, -1, -1, 1};
vector<pair<int, int>> moves;

void check(int x, int y) {
  moves.push_back({x + 1, y + 1});
  if (opponent == 0) {
    for (int i = 0; i < moves.size(); i++) {
      cout << moves[i].first << ' ' << moves[i].second << endl;
    }
  }
  for (int i = 0; i < 4; i++) {
    int a = x + di[i];
    int b = y + dj[i];
    if (a >= 0 && b >= 0 && a < n && b < n) {
      if (grid[a][b] == 'o') {
        int c = a + di[i];
        int d = b + dj[i];
        if (c >= 0 && d >= 0 && c < n && d < n) {
          if (grid[c][d] == '+') {
            grid[a][b] = '+';
            opponent--;
            check(c, d);
            grid[a][b] = 'o';
            opponent++;
          }
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'o') {
        opponent++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'K') {
        moves.clear();
        check(i, j);
      }
    }
  }
}