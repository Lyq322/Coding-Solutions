#include <iostream>

using namespace std;

int M, T, U, F, D;
char* track;

int main() {
  cin >> M >> T >> U >> F >> D;
  track = new char[T];
  for (int i = 0; i < T; i++) {
    cin >> track[i];
  }
  int total = 0;
  for (int i = 0; i < T; i++) {
    if (track[i] == 'u' || track[i] == 'd') {
      total = total + U + D;
    }
    else {
      total = total + 2*F;
    }
    if (total > M) {
      cout << i << endl;
      break;
    }
  }
}