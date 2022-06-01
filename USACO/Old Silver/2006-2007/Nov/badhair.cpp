#include <iostream>
#include <stack>

using namespace std;

int N;
int a[80000];
stack<int> cows;
int total = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cout << "total " << total << endl;
    if (cows.empty() || a[i] < cows.top()) {
      total += cows.size();
      cows.push(a[i]);
      cout << a[i] << endl;
    }
    else {
      while (!cows.empty()) {
        if (cows.top() > a[i]) {
          break;
        }
        cows.pop();
        cout << "pop\n";
      }
      total += cows.size();
      cows.push(a[i]);
      cout << a[i] << endl;
    }
  }
  cout << total << endl;
}