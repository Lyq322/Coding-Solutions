#include <iostream>

using namespace std;

int n;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
int grid[750][750] = {{0}};

int main() {
  cin >> n;
  int i = 0;
  int j = 0;
  int index = 0;
  int a = 2;
  grid[0][0] = 1;
  while (true) {
    if (n % 2 == 0 && i == n / 2 && j == n / 2 - 1) {
      break;
    }
    else if (n % 2 == 1 && i == n / 2 && j == n / 2) {
      break;
    }
    if (i + di[index] >= n || i + di[index] < 0 || j + dj[index] >= n || j + dj[index] < 0 || grid[i + di[index]][j + dj[index]] != 0) {
      index = (index + 1) % 4;
    }
    i += di[index];
    j += dj[index];
    grid[i][j] = a;
    a++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
}