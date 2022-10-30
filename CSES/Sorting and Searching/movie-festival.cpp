#include <iostream>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> pii;
 
int n;
pii movies[200000];
 
bool comp(pii a, pii b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}
 
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> movies[i].first >> movies[i].second;
  }
  sort(movies, movies + n, comp);
  int stop = 0;
  int ans = 0;
  int i = 0;
  while (i < n) {
    pii m = movies[i];
    if (movies[i].first >= stop) {
      ans++;
      stop = movies[i].second;
      i++;
    }
    else {
      i++;
    }
  }
  cout << ans << endl;
} 