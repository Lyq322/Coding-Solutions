#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;

string s;
set<pii> points;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

// 0 - left
// 1 - down
// 2 - right
// 3 - up
pii rotate(int x, int y, int dir, int posx, int posy) {
  int a = posx - x;
  int b = posy - y;
  if (dir == 0) {
    return {x - b, y + a};
  }
  else if (dir == 1 || dir == 3) {
    return {x - a, y - b};
  }
  else {
    return {x + b, y - a};
  }
}

int main() {
  cin >> s;
  int posx = 0;
  int posy = 0;
  int dir = 3;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      dir = (dir + 1) % 4;
    }
    else if (s[i] == 'R') {
      dir = (dir + 3) % 4;
    }
    else if (s[i] == 'F') {
      posx += di[dir];
      posy += dj[dir];
    }
  }
  int x = 0;
  int y = 0;
  int d = 3;
  pii finish;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      finish = rotate(x, y, 1, posx, posy);
      points.insert(finish);

      finish = rotate(x, y, 2, posx, posy);
      finish.first += di[d];
      finish.second += dj[d];
      points.insert(finish);

      d = (d + 1) % 4;
    }
    else if (s[i] == 'R') {
      finish = rotate(x, y, 1, posx, posy);
      points.insert(finish);

      finish = rotate(x, y, 0, posx, posy);
      finish.first += di[d];
      finish.second += dj[d];
      points.insert(finish);
      
      d = (d + 3) % 4;
    }
    else if (s[i] == 'F') {
      finish = rotate(x, y, 0, posx - di[d], posy - dj[d]);
      points.insert(finish);
      
      finish = rotate(x, y, 2, posx - di[d], posy - dj[d]);
      points.insert(finish);

      x += di[d];
      y += dj[d];
    }
  }
  cout << points.size() << endl;
} 