#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long int ll;
 
ll n, x;
bool found = false;
 
int main() {
  cin >> n >> x;
  int a;
  vector<pii> values(n);
  for (int i = 0; i < n; i++) {
    cin >> a; 
    values[i] = {a, i + 1};
  }
  sort(values.begin(), values.end());
  int left = 0;
  int right = n - 1;
  while (left < right) {
    if (values[left].first + values[right].first > x) {
      right--;
    }
    else if (values[left].first + values[right].first < x) {
      left++;
    }
    else {
      if (values[left].second < values[right].second) {
        cout << values[left].second << ' ' << values[right].second << endl;
      }
      else {
        cout << values[right].second << ' ' << values[left].second;
      }
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << endl;
  }
} 