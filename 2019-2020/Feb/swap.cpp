#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int intervals[100][2];
int numbers[100000];
int mark[100000];
int ans[100000];

void swap(int x, int y) {
  int temp;
  for (int i = x; i < (x+y) / 2 + (x+y) % 2; i++) {
    temp = numbers[i-1];
    numbers[i-1] = numbers[x+y-i-1];
    numbers[x+y-i-1] = temp;
  }
  return;
}

int main() {
  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    cin >> intervals[i][0];
    cin >> intervals[i][1];
  }
  for (int i = 0; i < N; i++) {
    numbers[i] = i + 1;
    mark[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    swap(intervals[i][0], intervals[i][1]);
  }
  for (int i = 0; i < N; i++) {
    if (mark[i] == 1) {
      continue;
    }
    if (numbers[i] == i + 1) {
      mark[i] = 1;
      ans[i] = numbers[i];
    }
    else {
      int index = i;
      vector<int> a = {};
      while (true) {
        if (mark[index] == 1) {
          break;
        }
        mark[index] = 1;
        a.push_back(numbers[index]);
        index = numbers[index] - 1;
      }
      for (int i = 0; i < a.size(); i++) {
        int p = i + K % a.size();
        p = p % a.size();
        ans[a[i]-1] = a[p];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}