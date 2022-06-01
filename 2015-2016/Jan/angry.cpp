#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int hay[50000];

bool check(int r) {
  int cows = 1;
  int s = hay[0];
  for (int i = 0; i < N; i++) {
    //cout << hay[i] << endl;
    if (hay[i] - s <= 2*r) {
      continue;
    }
    else {
      s = hay[i];
      cows++;
    }
  }
  if (cows > K) {
    return false;
  }
  return true;
}

void bs(int L, int R) {
  int M;
  while (L < R) {
    M = (L + R) / 2;
    //cout << "M " << M << endl;
    //cout << check(M) << endl;
    if (check(M)) {
      R = M;
    }
    else {
      L = M + 1;
    }
  }
  cout << L << endl;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> hay[i];
  }
  sort(hay, hay + N);
  //check(4);
  bs(1, 1000000);
}