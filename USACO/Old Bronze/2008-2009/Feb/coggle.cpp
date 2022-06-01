#include <iostream>
#include <string>
#include <vector>

using namespace std;

char letters[5][5];
int ans = 0;
int visited[5][5] = {0};
string s;
int found = 0;
int di[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void travel(int row, int column, int pos) {
  if (found == 1) {
    return;
  }
  if (pos == s.length()) {
    ans++;
    found = 1;
    return;
  }
  int r, c;
  for (int i = 0; i < 8; i++) {
    r = row + di[i];
    c = column + dj[i];
    if (r > -1 && r < 5 && c > -1 && c < 5) {
      if (letters[r][c] == s.at(pos) && visited[r][c] == 0) {
        visited[r][c] = 1;
        travel(r, c, pos + 1);
        visited[r][c] = 0;
      }
    }
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> letters[i][j];
      //cout << letters[i][j];
    }
    //cout << '\n';
  }
  cin.ignore();
  while (!cin.eof()) {
    getline(cin, s);
    found = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (letters[i][j] == s[0] && found == 0) {
          visited[i][j] = 1;
          travel(i, j, 1);
          visited[i][j] = 0;
        }
      }
    }
  }
  cout << ans << '\n';
}