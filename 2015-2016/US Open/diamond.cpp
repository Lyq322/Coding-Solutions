#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int ans = 1;
int diamond[50000];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> diamond[i];
  }
  sort(diamond, diamond + N);
  int left[N];
  int right[N];
  left[0] = 1;
  int a = 1;
  int i = 0;
  int j = 1;
  int t;
  while (true) {
    if (i >= N || j >= N) {
      break;
    }
    t = diamond[j] - diamond[i];
    if (t <= K && j - i + 1 > a) {
      a = j - i + 1;
    } 
    if (t > K || j + 1 == N) {
      i++;
    }
    else if (j + 1 < N) {
      left[j] = a;
      j++;
    }
  }
  left[N - 1] = a;
  right[N - 1] = 1;
  a = 1;
  i = N - 2;
  j = N - 1;
  while (true) {
    if (i < 0 || j < 0) {
      break;
    }
    t = diamond[j] - diamond[i];
    if (t <= K && j - i + 1 > a) {
      a = j - i + 1;
    } 
    if (t > K || i == 0) {
      j--;
    }
    else if (i > 0) {
      right[i] = a;
      i--;
    }
  }
  right[0] = a;
  for (int i = 0; i < N - 1; i++) {
    ans = max(ans, left[i] + right[i + 1]);
  }
  cout << max(max(ans, left[N - 1]), right[0]) << endl;
}