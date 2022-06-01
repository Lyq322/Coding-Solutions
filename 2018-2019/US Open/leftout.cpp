#include <iostream>

using namespace std;

int n;
char grid[1000][1000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (grid[0][i] == 'L') {
      for (int j = 0; j < n; j++) {
        if (grid[j][i] == 'L') {
          grid[j][i] = 'R';
        }
        else {
          grid[j][i] = 'L';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    if (grid[i][0] == 'L') {
      cout << "row " << i << endl;
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'L') {
          grid[i][j] = 'R';
        }
        else {
          grid[i][j] = 'L';
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
  int wrong = 0;
  int wrong_i, wrong_j;
  int wrong_i2, wrong_j2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'L') {
        wrong++;
        wrong_i = wrong_i2;
        wrong_j = wrong_j2;
        wrong_i2 = i;
        wrong_j2 = j;
      }
    }
  }
  if (wrong == 1) {
    cout << wrong_i2 + 1 << ' ' << wrong_j2 + 1 << endl;
  }
  else if (wrong == (n - 1) * (n - 1)) {
    bool first = true;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        if (grid[i][j] == 'R') {
          first = false;
          break;
        }
      }
    }
    if (first) {
      cout << "1 1" << endl;
    }
    else {
      cout << "-1" << endl;
    }
  }
  else {
    int right = 0;
    int right_index;
    if (wrong_i2 == wrong_i) {
      for (int i = 0; i < n; i++) {
        if (grid[wrong_i][i] == 'R') {
          right++;
          right_index = i;
        }
      }
      if (right != 1) {
        cout << "-1" << endl;
      }
      else {
        cout << wrong_i + 1<< ' ' << right_index + 1 << endl;
      }
    } 
    else if (wrong_j2 == wrong_j) {
      for (int i = 0; i < n; i++) {
        if (grid[i][wrong_j] == 'R') {
          right++;
          right_index = i;
        }
      }
      if (right != 1) {
        cout << "-1" << endl;
      }
      else {
        cout << right_index + 1 << ' ' << wrong_j + 1<< endl;
      }
    }
    else {
      cout << "-1" << endl;
    }
  }
} 