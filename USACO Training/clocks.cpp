#include <iostream>
#include <vector>

using namespace std;

int clocks[9];
vector<vector<int>> possible_moves = {{0,1,3,4}, {0,1,2}, {1,2,4,5}, {0,3,6}, {1,3,4,5,7}, {2,5,8}, {3,4,6,7}, {6,7,8}, {4,5,7,8}};
int moves[9] =
 {0};
int ans[9];
int length = -1;

void dfs(int pos) {
  if (pos == 9) {
    bool check = true;
    for (int i = 0; i < 9; i++) {
      if (clocks[i] % 4 != 0) {
        check = false;
        break;
      }
    }
    if (check) {
      int s = 0;
      for (int i = 0; i < 9; i++) {
        s += moves[i];
      }
      if (length == -1 || s < length) {
        for (int i = 0; i < 9; i++) {
          ans[i] = moves[i];
        }
        length = s;
      }
      else if (s == length) {
        bool larger = true;
        for (int i = 0; i < 9; i++) {
          if (moves[i] < ans[i]) {
            larger = false;
            break;
          }
        }
        if (!larger) {
          for (int i = 0; i < 9; i++) {
            ans[i] = moves[i];
          }
          length = s;
        }
      }
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    for (int k = 0; k < possible_moves[pos].size(); k++) {
      clocks[possible_moves[pos][k]] += i;
    }
    moves[pos] = i;
    dfs(pos + 1);
    moves[pos] = 0;
    for (int j = 0; j < possible_moves[pos].size(); j++) {
      clocks[possible_moves[pos][j]] -= i;
    }
  }
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> clocks[i];
    clocks[i] /= 3;
  }
  dfs(0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < ans[i]; j++) {
      cout << i + 1 << ' ';
    }
  }
  cout << endl;
} 