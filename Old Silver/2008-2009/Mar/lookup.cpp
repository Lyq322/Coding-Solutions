#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N;
  cin >> N;
  int cows[N];
  int ans[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  stack<int> index;
  for (int j = 0; j < N; j++) {
    if (index.empty()) {
      index.push(j);
    }
    else {
      if (cows[j] <= cows[index.top()]) {
        index.push(j);
      }
      else {
        while (!index.empty()) {
          if (cows[index.top()] < cows[j]) {
            ans[index.top()] = j + 1;
            index.pop();
          }
          else {
            break;
          }
        }
        index.push(j);
      }
    }
  }
  while (!index.empty()) {
    ans[index.top()] = 0;
    index.pop();
  }
  for (int k = 0; k < N; k++) {
    cout << ans[k] << '\n';
  }
}