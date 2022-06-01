#include <iostream>

int N;
int* marked;

using namespace std;

int main() {
  cin >> N;
  marked = new int[N + 1];
  for (int i = 0; i < N + 1; i++) {
    marked[i] = 0;
  }
  int a = 1;
  int b;
  while (true) {
    //cout << a << endl;
    marked[a] = 1;
    b = 2 * a;
    b = b % N;
    if (b == 0) {
      b = N;
    }
    if (marked[b] == 1) {
      break;
    }
    else {
      a = b;
    }
  }
  cout << a << endl;
}