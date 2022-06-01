#include <iostream>

using namespace std;

int N;
char moves[100000];
int ans = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> moves[i];
  }
  int a = 0;
  // Paper Paper
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'H') {
      a++;
    }
  }
  ans = max(ans, a);
  // Scissor Paper
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'P') {
      a++;
    }
    else if (moves[i] == 'H') {
      a--;
    }
    ans = max(ans, a);
  }
  int b = a;
  // Hoof Scissor
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'S') {
      a++;
    }
    else if (moves[i] == 'P') {
      a--;
    }
    ans = max(ans, a);
  }
  // Paper Hoof
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'H') {
      a++;
    }
    else if (moves[i] == 'S') {
      a--;
    }
    ans = max(ans, a);
  }
  // Paper Scissor
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'H') {
      b++;
    }
    else if (moves[i] == 'P') {
      b--;
    }
    ans = max(ans, b);
  }
  // Hoof Paper
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'S') {
      b++;
    }
    else if (moves[i] == 'H') {
      b--;
    }
    ans = max(ans, b);
  }
  // Scissor Hoof
  for (int i = 0; i < N; i++) {
    if (moves[i] == 'P') {
      b++;
    }
    else if (moves[i] == 'S') {
      b--;
    }
    ans = max(ans, b);
  }
  cout << ans << endl;
}