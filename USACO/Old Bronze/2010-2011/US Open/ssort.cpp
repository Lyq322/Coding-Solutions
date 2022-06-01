#include <iostream>
#include <math.h>

using namespace std;

int N;
int *cows;
int ans = 0;

void skewed(int left, int right) {
  //cout << "left " << left << " right " << right << endl;
  //for (int i = 0; i < N; i++) {
  //  cout << cows[i] << ' ';
  //}
  //cout << endl;
  if (left >= right) {
    return;
  }
  int middle = (left + right) / 2;
  skewed(left, middle);
  skewed(middle + 1, right);
  bool b = false;
  //cout << "tuna\n";
  for (int i = 0; i < middle - left + 1; i++) {
    //cout << cows[i + left] << ' ' << cows[i + middle + 1] << endl;
    if (cows[i + left] > cows[i + middle + 1]) {
      b = true;
      break;
    }
    else if (cows[i + left] < cows[i + middle + 1]) {
      break;
    }
  }
  //cout << "b " << b << endl;
  if (b) {
    int temp;
    for (int i = 0; i < middle - left + 1; i++) {
      temp = cows[i + left];
      cows[i + left] = cows[i + middle + 1];
      cows[i + middle + 1] = temp;
    }
    ans = ans + (middle - left + 1) * (middle - left + 1) * 2;
  }
  //cout << "ans " << ans << endl;
}

int main() {
  cin >> N;
  N = pow(2.0, N);
  cows = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  skewed(0, N - 1);
  cout << ans << endl;
  for (int i = 0; i < N; i++) {
    cout << cows[i] << endl;
  }
}