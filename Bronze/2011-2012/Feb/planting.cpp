#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

/*
2
0 5 4 1
2 4 6 2
*/

struct point {
  int posx, posy1, posy2, val;
};

int n;
point points[20];
vector<pii> line;

bool comp(point a, point b) {
  if (a.posx == b.posx) {
    return a.posy1 < b.posy1;
  }
  return a.posx < b.posx;
}

bool comp2(pii a, pii b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int calculate() {
  int d = 0;
  int begin = line[0].first;
  int total = 0;
  for (int i = 0; i < line.size(); i++) {
    pii current = line[i];
    if (current.second == 0) {
      if (d == 0) {
        begin = current.first;
      }
      d++;
    }
    else {
      d--;
      if (d == 0) {
        total += current.first - begin;
      }
    }
  }
  return total;
}

int main() {
  cin >> n;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> points[2 * i].posx >> a;
    cin >> points[2 * i + 1].posx >> b;
    points[2 * i].posy1 = b;
    points[2 * i].posy2 = a;
    points[2 * i + 1].posy1 = b;
    points[2 * i + 1].posy2 = a;
    points[2 * i].val = 0;
    points[2 * i + 1].val = 1;
  }
  sort(points, points + 2 * n, comp);
  int region;
  int begin;
  int total = 0;
  for (int i = 0; i < 2 * n; i++) {
    point current = points[i];
    if (i == 0) {
      line.push_back({current.posy1, 0});
      line.push_back({current.posy2, 1});
      sort(line.begin(), line.end(), comp2);
      region = calculate();
      begin = current.posx;
    }
    else {
      if (current.val == 0) {
        line.push_back({current.posy1, 0});
        line.push_back({current.posy2, 1});
        sort(line.begin(), line.end(), comp2);
        total += region * (current.posx - begin);
        region = calculate();
        begin = current.posx;
      }
      else {
        for (int i = 0; i < line.size(); i++) {
          if (line[i].first == current.posy1 && line[i].second == 0) {
            a = i;
            break;
          }
        }
        line.erase(line.begin() + a);
        for (int i = 0; i < line.size(); i++) {
          if (line[i].first == current.posy2 && line[i].second == 1) {
            a = i;
            break;
          }
        }
        line.erase(line.begin() + a);
        total += region * (current.posx - begin);
        region = calculate();
        begin = current.posx;
      }
    }
  }
  cout << total << endl;
} 