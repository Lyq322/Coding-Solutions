#include <iostream>

using namespace std;

typedef pair<int, int> pii;
int n;
pii moves[1000];
pii current[4] = {{0, 1}, {1, 1}, {0, 0}, {1, 0}};
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int dir = 0;
int min_x = 0;
int min_y = 0;
int max_x = 1;
int max_y = 1;

// FL = Front Left = 0
// FR = Front Right = 1
// RL = Rear Left = 2
// RR = Rear Right = 3
// Forward = 0
// Right = 1
// Down = 2
// Left = 3
// Pivot = 4

pii rotate(int x, int y, int posx, int posy) {
  int a = posx - x;
  int b = posy - y;
  return {x + b, y - a};
}

bool check() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j && current[i] == current[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s.substr(0, 2) == "FL") {
      moves[i].first = 0;
    }
    else if (s.substr(0, 2) == "FR") {
      moves[i].first = 1;
    }
    else if (s.substr(0, 2) == "RL") {
      moves[i].first = 2;
    }
    else {
      moves[i].first = 3;
    }
    if (s[2] == 'F') {
      moves[i].second = 0;
    }
    else if (s[2] == 'R') {
      moves[i].second = 1;
    }
    else if (s[2] == 'B') {
      moves[i].second = 2;
    }
    else if (s[2] == 'L'){
      moves[i].second = 3;
    }
    else {
      moves[i].second = 4;
    }
  }
  bool failed = false;
  for (int i = 0; i < n; i++) {
    if (moves[i].second == 4) {
      for (int j = 0; j < 4; j++) {
        current[j] = rotate(current[moves[i].first].first, current[moves[i].first].second, current[j].first, current[j].second);
      }
      dir = (dir + 1) % 4;
      if (!check()) {
        cout << "failed\n";
        for (int j = 0; j < 4; j++) {
          cout << current[j].first << ' ' << current[j].second << endl;
        }
        failed = true;
        break;
      }
    }
    else {
      int new_dir = (dir + moves[i].second) % 4;
      int new_x = current[moves[i].first].first + di[new_dir];
      int new_y = current[moves[i].first].second + dj[new_dir];
      current[moves[i].first] = {new_x, new_y};
      if (!check()) {
        cout << "failed\n";
        for (int j = 0; j < 4; j++) {
          cout << current[j].first << ' ' << current[j].second << endl;
        }
        failed = true;
        break;
      }
    }
    for (int j = 0; j < 4; j++) {
      min_x = min(min_x, current[j].first);
      min_y = min(min_y, current[j].second);
      max_x = max(max_x, current[j].first);
      max_y = max(max_y, current[j].second);
    }
    for (int j = 0; j < 4; j++) {
      cout << current[j].first << ' ' << current[j].second << endl;
    }
    cout << endl;
  }
  cout << min_x << ' ' << max_x << ' ' << min_y << ' ' << max_y << endl;
  if (failed) {
    cout << -1 << endl;
  }
  else {
    cout << (max_x - min_x + 1) * (max_y - min_y + 1);
  }
} 