#include <iostream>

using namespace std;

int n;
int ans = 0;

void calculate(int left, int right) {
  if (right - left + 1 == 1) {
    return;
  }
  else if (right - left + 1 == 2) {
    ans += left * right;
  }
  else {
    int new_right = (left + right) / 2;
    int new_left = new_right + 1;
    calculate(left, new_right);
    calculate(new_left, right);
  }
}

int main() {
  cin >> n;
  calculate(1, n);
  cout << ans << endl;
} 