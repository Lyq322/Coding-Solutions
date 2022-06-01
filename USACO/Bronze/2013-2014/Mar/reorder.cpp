#include <iostream>

int N;
int* cows;
int* visited;
int* reverse;
int best = -1;
int ans = 0;

using namespace std;

void cycle(int pos, int length) {
  //cout << "pos " << pos << endl;
  if (visited[pos] == 1) {
    if (length > 1) {
      ans++;
    }
    if (length > best) {
      best = length;
    }
    return;
  }
  visited[pos] = 1;
  cycle(reverse[cows[pos]], length + 1);
}

int main() {
  cin >> N;
  cows = new int[N];
  visited = new int[N];
  reverse = new int[N + 1];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
    visited[i] = 0;
  }
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    reverse[a] = i;
  }
  for (int i = 0; i < N; i++) {
    if (visited[i] == 0) {
      //cout << i << endl;
      cycle(i, 0);
    }
  }
  if (ans != 0) {
    cout << ans << ' ' << best << endl;
  }
  else {
    cout << ans << ' ' << -1 << endl;
  }
}