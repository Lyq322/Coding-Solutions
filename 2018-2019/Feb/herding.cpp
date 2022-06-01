#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cows[100000];
int minimum, maximum;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  sort(cows, cows + N);
  int i = 0;
  int j = 1;
  int left = i, right = j;
  int num = 0;
  while (i < N && j < N) {
    if (j - i + 1 > num) {
      num = j - i + 1;
      left = i;
      right = j;
    }
    if (cows[j + 1] - cows[i] + 1 <= N) {
      j++;
    }
    else {
      if (i == j) {
        j++;
      }
      i++;
    }
  }
  if (left == 1 && right == N - 1) {
    if (cows[right] - cows[left] + 1 == N) {
      minimum = 1;
    }
    else {
      minimum = 2;
    }
  }
  else if (left == 0 && right == N - 2) {
    if (cows[right] - cows[left] + 1 == N) {
      minimum = 1;
    }
    else {
      if (cows[right] + 2 == cows[N - 1]) {
        minimum = 1;
      }
      else {
        minimum = 2;
      }
    }
  }
  else {
    minimum = N - num;
  }
  cout << minimum << endl;
  if (cows[1] - cows[0] <= cows[N - 1] - cows[N - 2]) {
    maximum = cows[N - 1] - cows[1] + 1 - N + 1;
  }
  else {
    maximum = cows[N - 2] - cows[0] + 1 - N + 1;
  }
  cout << maximum << endl;
}