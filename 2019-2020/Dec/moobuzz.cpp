#include <iostream>

using namespace std;

long long int N;

int main() {
  cin >> N;
  if (N % 8 == 0) {
    cout << N * 15 / 8 - 1;
  }
  else if (N % 8 == 1) {
    cout << (N - 1) * 15 / 8 + 1;
  }
  else if (N % 8 == 2) {
    cout << (N - 2) * 15 / 8 + 2;
  }
  else if (N % 8 == 3) {
    cout << (N - 3) * 15 / 8 + 4;
  }
  else if (N % 8 == 4) {
    cout << (N - 4) * 15 / 8 + 7;
  }
  else if (N % 8 == 5) {
    cout << (N - 5) * 15 / 8 + 8;
  }
  else if (N % 8 == 6) {
    cout << (N - 6) * 15 / 8 + 11;
  }
  else if (N % 8 == 7) {
    cout << (N - 7) * 15 / 8 + 13;
  }
}