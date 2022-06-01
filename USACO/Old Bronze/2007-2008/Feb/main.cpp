#include <iostream>

using namespace std;

int N;
int* cows;
int ans;

int main() {
  cin >> N;
  cows = new int[N];
  int one = 0;
  int two = 0;
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
    if (cows[i] == 1) {
      one++;
    }
  }
  int total;
  ans = one;
  for (int i = 0; i < N; i++) {
    if (cows[i] == 1) {
      one--;
    }
    else {
      two++;
    }
    total = one + two;
    //cout << total << endl;
    if (ans == -1 || total < ans) {
      ans = total;
    }
  }
  cout << ans << endl;
}