#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct cow {
  int x;
  int y;
  int index;
  bool stop;
};

int n;
cow east_cows[1000];
cow north_cows[1000];
int blame[1000] = {0};

bool comp1(cow a, cow b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

bool comp2(cow a, cow b) {
  if (a.y != b.y) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

int main() {
  cin >> n;
  char dir;
  int x, y;
  int east = 0, north = 0;
  for (int i = 0; i < n; i++) {
    cin >> dir >> x >> y;
    if (dir == 'E') {
      east_cows[east].x = x;
      east_cows[east].y = y;
      east_cows[east].index = i;
      east++;
    }
    else {
      north_cows[north].x = x;
      north_cows[north].y = y;
      north_cows[north].index = i;
      north++;
    }
  }
  sort(east_cows, east_cows + east, comp2);
  sort(north_cows, north_cows + north, comp1);
  for (int i = 0; i < north; i++) {
    cout << north_cows[i].x << ' ' << north_cows[i].y << endl;
  }
  for (int i = 0; i < east; i++) {
    for (int j = 0; j < north; j++) {
      if (north_cows[j].stop || east_cows[i].stop) {
        continue;
      }
      if (north_cows[j].x < east_cows[i].x || north_cows[j].y > east_cows[i].y) {
        continue;
      }
      if (north_cows[j].x - east_cows[i].x < east_cows[i].y - north_cows[j].y) {
        north_cows[j].stop = true;
        blame[east_cows[i].index] += 1 + blame[north_cows[j].index];
      }
      else if (north_cows[j].x - east_cows[i].x > east_cows[i].y - north_cows[j].y) {
        east_cows[i].stop = true;
        blame[north_cows[j].index] += 1 + blame[east_cows[i].index];
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << blame[i] << endl;
  }
}