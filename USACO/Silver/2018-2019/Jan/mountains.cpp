#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> mountains;
int ans = 0;

bool comp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int main() {
  cin >> N;
  int x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    pii m = {x - y, x + y};
    mountains.push_back(m);
  }
  sort(mountains.begin(), mountains.end(), comp);
  //cout << endl;
  //for (int i = 0; i < N; i++) {
  //  cout << mountains[i].first << ' ' << mountains[i].second << endl;
  //}
  int i = 0;
  int j = 1;
  while (i < N && j < N) {
    //cout << "i " << i << endl;
    //cout << "j " << j << endl;
    //cin.ignore();
    //cout << mountains[i].first << ' ' << mountains[j].first << endl;
    //cout << mountains[i].second << ' ' << mountains[j].second << endl;
    if (mountains[i].first <= mountains[j].first && mountains[i].second >= mountains[j].second) {
      j++;
      ans++;
    }
    else {
      i = j;
      j++;
    }
  }
  cout << N - ans << endl;
}