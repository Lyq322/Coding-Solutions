#include <iostream>

using namespace std;

int n;
int bales[20];
int minimum_max = -1;

void dfs(int sum1, int sum2, int sum3, int index) {
  if (index == n) {
    if (minimum_max > max(max(sum1, sum2), sum3) || minimum_max == -1) {
      minimum_max = max(max(sum1, sum2), sum3);
    }
    return;
  }
  //add to the first sum
  if (sum1 + bales[index] < minimum_max || minimum_max == -1) {
    dfs(sum1 + bales[index], sum2, sum3, index + 1);
  }
  //add to the second sum
  if (sum2 + bales[index] < minimum_max || minimum_max == -1) {
    dfs(sum1, sum2 + bales[index], sum3, index + 1);
  }
  //add to the third sum
  if (sum3 + bales[index] < minimum_max || minimum_max == -1) {
    dfs(sum1, sum2, sum3 + bales[index], index + 1);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> bales[i];
  }
  dfs(0, 0, 0, 0);
  cout << minimum_max << endl;
}