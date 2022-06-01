#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> trees;
int fruit;

bool comp(int a, int b) {
  return a % fruit > b % fruit;
}

int main() {
  cin >> n >> k;
  int b;
  int maximum = 0;
  for (int i = 0; i < n; i++) {
    cin >> b;
    trees.push_back(b);
    maximum = max(maximum, trees[i]);
  }
  int ans = 0;
  for (int i = 1; i <= maximum; i++) {
    int baskets = 0;
    fruit = i;
    for (int j = 0; j < trees.size(); j++) {
      baskets += trees[j] / fruit;
    }
    if (baskets < k / 2) {
      break;
    }
    if (baskets >= k) {
      ans = max(ans, (k / 2) * i);
      continue;
    }
    sort(trees.begin(), trees.end(), comp);
    int total = fruit * (baskets - k / 2);
    for (int j = 0; j < trees.size() && j + baskets < k; j++) {
      total += (trees[j] % fruit);
    }
    ans = max(ans, total);
  }
  cout << ans << endl;
}