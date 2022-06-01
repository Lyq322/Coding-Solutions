#include <iostream>

using namespace std;

string s;
long long int N;

int main() {
  cin >> s >> N;
  N--;
  long long int L = s.length();
  while (L < N) {
    //cout << L << endl;
    L = L * 2;
  }
  while (L > s.length()) {
    //cout << L << endl;
    if (N == L / 2) {
      N = N - 1;
      L = L / 2;
    }
    else if (N < L / 2) {
      L = L / 2;
    }
    else {
      N = N - L / 2 - 1;
      L = L / 2;
    }
  }
  cout << s.at(N);
}