#include <iostream>
#include <math.h>

using namespace std;

int N;

bool prime(int x) {
  for (int i = 2; i < sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve(int num, int len) {
  if (len == N) {
    cout << num << '\n';
    return;
  }
  int one = num * 10 + 1;
  int three = num * 10 + 3;
  int seven = num * 10 + 7;
  int nine = num * 10 + 9;
  if (prime(one)) {
    solve(one, len + 1);
  }
  if (prime(three)) {
    solve(three, len + 1);
  }
  if (prime(seven)) {
    solve(seven, len + 1);
  }
  if (prime(nine)) {
    solve(nine, len + 1);
  }
}

int main() {
  cin >> N;
  solve(2, 1);
  solve(3, 1);
  solve(5, 1);
  solve(7, 1);
}