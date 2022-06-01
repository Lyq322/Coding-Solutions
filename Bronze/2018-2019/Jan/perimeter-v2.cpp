#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int map[1002][1002];
int perimeter, area;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
stack<int> row;
stack<int> col;
int marker = 0;
int ans_a = -1;
int ans_p = -1;

int main() {
  cin >> N;
  char c;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      cin >> c;
      if (c == '#') {
        map[i][j] = -1;
      }
      else {
        map[i][j] = 0;
      }
    }
  }
  int current_i, current_j;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      if (map[i][j] == -1) {
        area = 0;
        perimeter = 0;
        marker++;
        row.push(i);
        col.push(j);
        while (!row.empty()) {
          current_i = row.top();
          current_j = col.top();
          row.pop();
          col.pop();
          if (map[current_i][current_j] != -1) {
            continue;
          }
          area++;
          map[current_i][current_j] = marker;
          for (int i = 0; i < 4; i++) {
            int a = current_i + di[i];
            int b = current_j + dj[i];
            if (map[a][b] == -1) {
              row.push(a);
              col.push(b);
            }
            else if (map[a][b] == 0) {
              perimeter++;
            }
          } 
        }
        if (ans_a == -1) {
          ans_a = area;
          ans_p = perimeter;
        }
        else if (ans_a < area) {
          ans_a = area;
          ans_p = perimeter;
        }
        else if (ans_a == area && perimeter < ans_p) {
          ans_a = area;
          ans_p = perimeter;
        }
      }
    }
  }
  cout << ans_a << ' ' << ans_p << endl;
}