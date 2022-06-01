#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int marked[1000][1000];
char map[1000][1000];
int perimeter, area;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
vector<vector<int>> v;

bool comp(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] > b[0];
}

void ff(int x, int y) {
  //cout << endl;
  for (int i = 0; i < 4; i++) {
    //cout << "perimeter " << perimeter << endl;
    int a = x + di[i];
    int b = y + dj[i];
    //cout << "x " << x << ' ' << "y " << y << endl;
    //cout << "a " << a << ' ' << "b " << b << endl;
    if (a > -1 && b > -1 && a < N && b < N) {
      if (marked[a][b] == 0 && map[a][b] == '#') {
        area++;
        marked[a][b] = 1;
        ff(a, b);
      }
      else if (map[a][b] == '.') {
        perimeter++;
      }
    }
    else {
      perimeter++;
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      marked[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (marked[i][j] == 0 && map[i][j] == '#') {
        marked[i][j] = 1;
        perimeter = 0;
        area = 1;
        ff(i, j);
        vector<int> t = {};
        t.push_back(area);
        t.push_back(perimeter);
        v.push_back(t);
      }
    }
  }
  sort(v.begin(), v.end(), comp);
  cout << v[0][0] << ' ' << v[0][1] << endl;
}