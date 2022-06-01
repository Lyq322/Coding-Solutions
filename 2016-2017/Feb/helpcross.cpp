#include <iostream>
#include <algorithm>

using namespace std;

int C, N;
int* chickens;
int** cows;
int* visited;
int ans = 0;

int main() {
  cin >> C >> N;
  chickens = new int[C];
  cows = new int*[N];
  visited = new int[N];
  for (int i = 0; i < C; i++) {
    cin >> chickens[i];
  }
  sort(chickens, chickens + C);
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    cows[i] = new int[2];
    visited[i] = 0;
    cows[i][0] = a;
    cows[i][1] = b;
  }
  int s, index;
  for (int i = 0; i < C; i++) {
    s = 1000050000;
    index = -1;
    for (int j = 0; j < N; j++) {
      if (visited[j] == 0 && cows[j][0] <= chickens[i] && cows[j][1] >= chickens[i]) {
        if (cows[j][1] - chickens[i] < s) {
          s = cows[j][1] - chickens[i];
          index = j;
        }
      }
    }
    if (index != -1) {
      visited[index] = 1;
      ans++;
    }
  }
  cout << ans << endl;
}