#include <iostream>

using namespace std;

int N;
int pay[100000];

int main() {
  cin >> N;
  int total = 0;
  int distance = 0;
  bool b = false;
  int mark;
  for (int i = 0; i < N; i++) {
    cin >> pay[i];
    total = total + pay[i];
    if (!b && total < 0) {
      b = true;
      mark = i;
    }
    else if (b && total >= 0) {
      b = false;
      distance = distance + 2 * (i - mark);
    }
  }
  cout << distance + N << endl;
}