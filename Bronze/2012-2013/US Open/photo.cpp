#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

/*
15 4
1 13
3 9
5 11
6 7
*/

int n, k;
pii enemies[1000];
int ans = 1;

bool comp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
} 

int main() {
  cin >> n >> k;
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    if (a > b) {
      enemies[i].first = b;
      enemies[i].second = a;
    }
    else {
      enemies[i].first = a;
      enemies[i].second = b;
    }
  }
  sort(enemies, enemies + k, comp);
  int i = 0;
  while (i < k) {
    cout << "i " << i << endl;
    int j = i + 1;
    int minimum = enemies[i].second;
    while (j < k && enemies[j].first < minimum) {
      cout << enemies[j].second << ' ' << minimum << endl;
      if (minimum == -1 || enemies[j].second < minimum) {
        minimum = enemies[j].second;
      }
      j++;
      cout << "minimum " << minimum << endl;
    }
    cout << "j " << j << endl;
    j = i + 1;
    while (j < k && enemies[j].first < minimum) {
      cout << enemies[j].first << endl;
      j++;
    }
    cout << "j " << j << endl;
    ans++;
    i = j;
  }
  cout << ans << endl;
}