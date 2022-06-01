#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
  cin >> N;
  int a, b;
  int length = 2 * (N - 1);
  int connections[length];
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    connections[2*i] = a;
    connections[2*i + 1] = b;
  }
  //cout << "tuna\n";
  sort(connections, connections + length);
  int c[connections[length - 1]];
  for (int i = 0; i < connections[length - 1]; i++) {
    c[i] = 0;
  }
  for (int i = 0; i < length; i++) {
    c[connections[i]]++;
  }
  sort(c, c + connections[length - 1]);
  cout << c[connections[length - 1]-1] + 1;
}