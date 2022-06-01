#include <iostream>

using namespace std;

int n, m;
int race[1000000][2];
int ans = 0;

int main() {
  cin >> n >> m;
  int time = 0;
  int distance = 0;
  int s, t;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    for (int j = time; j < time + t; j++) {
      distance += s;
      race[j][0] = distance;
    }
    time += t;
  }
  for (int i = time; i < 1000000; i++) {
    race[i][0] = distance;
  }
  time = 0;
  distance = 0;
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    for (int j = time; j < time + t; j++) {
      distance += s;
      race[j][1] = distance;
    }
    time += t;
  }
  for (int i = time; i < 1000000; i++) {
    race[i][1] = distance;
  }
  int leader = -1;
  for (int i = 0; i < 1000000; i++) {
    if (race[i][0] > race[i][1]) {
      if (leader == -1) {
        leader = 1;
      }
      else if (leader == 2) {
        leader = 1;
        ans++;
      }
    }
    else if (race[i][0] < race[i][1]) {
      if (leader == -1) {
        leader = 2;
      }
      else if (leader == 1) {
        leader = 2;
        ans++;
      }
    }
  }
  cout << ans << endl;
}