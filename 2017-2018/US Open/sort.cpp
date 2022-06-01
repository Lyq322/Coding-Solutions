#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
pair<int, int> num[100000];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i].first;
    num[i].second = i;
  }
  sort(num, num + N);
  int maximum = 0;
  for (int i = 0; i < N; i++) {
    maximum = max(maximum, num[i].second - i);
  }
  cout << maximum + 1 << endl;
}