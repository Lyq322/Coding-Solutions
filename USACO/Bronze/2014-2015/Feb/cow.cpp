#include <iostream>

using namespace std;

int N;
char cow[100000];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cow[i];
  }
  long long int t = 0;
  long long int w = 0;
  long long int total = 0;
  for (int i = N - 1; i > -1; i--) {
    cout << "w " << w << " t " << t << " total " << total << endl;
    if (cow[i] == 'W') {
      w++;
    }
    else if (cow[i] == 'O') {
      t += w;
    }
    else {
      total += t;
    }
  }
  cout << total << endl;
}