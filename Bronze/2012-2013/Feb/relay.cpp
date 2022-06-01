#include <iostream>

using namespace std;

int n;
int cows[1000];
bool visited[1000] = {0};
bool loop = false;

void check(int pos) {
  int next = cows[pos];
  if (next == -1) {
    return;
  }
  if (visited[next]) {
    loop = true;
  }
  else {
    visited[next] = true;
    check(next);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cows[i];
    cows[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[j] = false;
    }
    visited[i] = true;
    loop = false;
    check(i);
    if (!loop) {
      ans++;
    }
  }
  cout << ans << endl;
}