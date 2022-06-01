#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int* cards;
vector<int> bessie;
vector<int> elsie;

int main() {
  cin >> N;
  cards = new int[2*N+1];
  int a;
  for (int i = 1; i < 2*N+1; i++) {
    cards[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> a;
    cards[a] = 1;
    elsie.push_back(a);
  }
  for (int i = 1; i < 2 * N + 1; i++) {
    if (cards[i] == 0) {
      bessie.push_back(i);
    }
  }
  sort(bessie.begin(), bessie.end());
  sort(elsie.begin(), elsie.end());
  int i = 0;
  int j = 0;
  int ans = 0;
  while (i < N && j < N) {
    if (bessie[i] < elsie[j]) {
      i++;
    }
    else {
      i++;
      j++;
      ans++;
    }
  }
  cout << ans << endl;
}