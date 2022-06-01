#include <iostream>

int N;
int* lap;
int** signal;
int* cows;
//int* run_time;
int* time_left;

using namespace std;

int main() {
  cin >> N;
  lap = new int[N];
  signal = new int*[N];
  cows = new int[N];
  time_left = new int[N];
  int M;
  for (int i = 0; i < N; i++) {
    cin >> lap[i];
    cin >> M;
    cows[i] = 1;
    signal[i] = new int[M + 1];
    signal[i][0] = M;
    time_left[i] = -1;
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      signal[i][j + 1] = a;
    }
  }
  int t = 0;
  bool b;
  while (true) {
    if (t == 0) {
      cows[0] = 2;
      t = lap[0];
      time_left[0] = 0;
    }
    else {
      for (int i = 0; i < N; i++) {
        if (time_left[i] == 0) {
          cows[i] = 3;
          time_left[i] = -1;
          for (int j = 1; j < signal[i][0] + 1; j++) {
            if (cows[signal[i][j] - 1] == 1) {
              cows[signal[i][j] - 1] = 2;
              time_left[signal[i][j] - 1] = lap[signal[i][j] - 1];
            }
          }
        }
      }
      int mini = 1000000;
      for (int i = 0; i < N; i++) {
        if (time_left[i] != -1 && time_left[i] < mini) {
          mini = time_left[i];
        }
      }
      t = t + mini;
      for (int i = 0; i < N; i++) {
        if (time_left[i] != -1) {
          time_left[i] = time_left[i] - mini;
        }
      }
    }
    b = true;
    for (int i = 0; i < N; i++) {
      if (cows[i] != 3) {
        b = false;
      }
    }
    if (b) {
      break;
    }
  }
  cout << t - 1000000 << endl;
}