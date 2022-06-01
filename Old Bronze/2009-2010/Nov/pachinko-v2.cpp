#include <iostream>
#include <algorithm>

using namespace std;

int R;
int** pinball;

int main() {
  cin >> R;
  //cout << endl;
  pinball = new int*[R];
  for (int i = 0; i < R; i++) {
    pinball[i] = new int[R];
    for (int j = 0; j < i + 1; j++) {
      cin >> pinball[i][j];
    }
  }
  int sum[R];
  for (int i = 0; i < R; i++) {
    sum[i] = pinball[R-1][i];
    //cout << sum[i];
  }
  for (int i = R - 1; i > -1; i--) {
    int sum2[R];
    //cout << "sum2\n";
    for (int j = 0; j < i; j++) {
      //cout << sum[j] << ' ' << sum[j+1] << endl;
      //cout << "pin " << pinball[i-1][j] << endl;
      sum2[j] = max(sum[j], sum[j+1]) + pinball[i-1][j];
      //cout << sum2[j] << endl;
    }
    //cout << endl;
    for (int j = 0; j < i; j++) {
      sum[j] = sum2[j];
      //cout << sum[j] << ' ';
    }
    //cout << endl;
  }
  cout << sum[0] << endl;
}