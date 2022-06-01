#include <iostream>

using namespace std;

int N;
int best = 1;

void carry(int cows[], int set[], int N, int one) {
  int c[one];
  //cout << '\n';
  int pos = 0;
  for (int j = 0; j < N; j++) {
    if (set[j] == 1) {
      c[pos] = cows[j];
      //cout << c[pos] << ' ';
      pos++;
    }
  }
  //cout << '\n';
  int x = c[0];
  int temp;
  for (int i = 1; i < one; i++) {
    int y = c[i]; 
    temp = x;
    //cout << "x " << x << " y " << y << '\n';
    while (x > 0 && y > 0) {
      if (x % 10 + y % 10 >= 10) {
        return;
      }
      x = x / 10;
      y = y / 10;
    }
    x = c[i] + temp;
  }
  if (best < one) {
    //cout << "best\n";
    best = one;
  }
  return;
}

void subset(int pos, int N, int ans[], int cows[], int one) {
  //cout << "subset\n";
  /*
  for (int i = 0; i < pos; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';*/
  if (pos == N) {
    if (best < one) {
      carry(cows, ans, N, one);
    }
    return;
  }
  ans[pos] = 0;
  subset(pos + 1, N, ans, cows, one);
  ans[pos] = 1;
  subset(pos + 1, N, ans, cows, one + 1);
}

int main() {
  cin >> N;
  int cows[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  int ans[N];
  subset(0, N, ans, cows, 0);
  cout << best << '\n';
}