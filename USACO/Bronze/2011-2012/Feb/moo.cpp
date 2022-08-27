#include <iostream>

using namespace std;

// Hello
int n;

int main() {
  cin >> n;
  int a = 3;
  int b = 0;
  int level = 0;
  while (a < n) {
    level++;
    b = a;
    a = a * 2 + level + 3;
  }
  while (true) {
    cout << "n " << n << " b " << b << " l " << level << endl;
    if (b < n && n <= b + level + 3) {
      if (n == b + 1) {
        cout << 'm' << endl;
      }
      else {
        cout << 'o' << endl;
      }
      break;
    }
    else if (level == 0) {
      if (n == 1) {
        cout << 'm' << endl;
      }
      else {
        cout << 'o' << endl;
      }
      break;
    }
    if (n > b + level + 3) {
      n = n - b - level - 3;
      b = b - level - 2;
      b = b / 2;
      level--;
    }
    else {
      b = b - level - 2;
      b = b / 2;
      level--;
    }
  }
}