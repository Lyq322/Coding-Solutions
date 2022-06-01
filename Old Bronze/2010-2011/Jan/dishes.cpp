#include <iostream>
#include <stack>

using namespace std;

int N;

int main() {
  cin >> N;
  int C, D;
  stack<int> unwashed;
  stack<int> washed;
  stack<int> dried;
  int a = N;
  for (int i = 0; i < N; i++) {
    unwashed.push(a);
    a--;
  }
  int w = 0;
  int d = 0;
  while (w != N || d != N) {
    cin >> C >> D;
    if (C == 1) {
      for (int j = 0; j < D; j++) {
        washed.push(unwashed.top());
        unwashed.pop();
      }
      w = w + D;
    }
    else {
      for (int j = 0; j < D; j++) {
        dried.push(washed.top());
        washed.pop();
      }
      d = d + D;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << dried.top() << endl;
    dried.pop();
  }
}