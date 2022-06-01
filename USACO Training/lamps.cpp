#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> on;
vector<int> off;
vector<string> ans;

int main() {
  cin >> n >> c;
  int a;
  cin >> a;
  while (a != -1) {
    on.push_back(a);
    cin >> a;
  }
  cin >> a;
  while (a != -1) {
    off.push_back(a);
    cin >> a;
  }
  string lamps[8] = {"111111", "000000", "010101", "101010", "011011", "100100", "110001", "001110"};
  vector<int> combinations;
  if (c == 1) {
    combinations.push_back(1);
    combinations.push_back(2);
    combinations.push_back(3);
    combinations.push_back(4);
  }
  else if (c == 2) {
    combinations.push_back(1);
    combinations.push_back(2);
    combinations.push_back(3);
    combinations.push_back(5);
    combinations.push_back(6);
    combinations.push_back(7);
    combinations.push_back(0);
  }
  else if (c == 0) {
    combinations.push_back(0);
  }
  else {
    combinations.push_back(1);
    combinations.push_back(2);
    combinations.push_back(3);
    combinations.push_back(4);
    combinations.push_back(5);
    combinations.push_back(6);
    combinations.push_back(7);
    combinations.push_back(0);
  }
  for (int i = 0; i < combinations.size(); i++) {
    string lamp = lamps[combinations[i]];
    cout << lamp << endl;
    bool b = true;
    for (int j = 0; j < on.size(); j++) {
      cout << on[j] - 1 << endl;
      if (lamp.at((on[j] - 1) % 6) == '0') {
        b = false;
        break;
      }
    }
    for (int j = 0; j < off.size(); j++) {
      if (lamp.at((off[j] - 1) % 6) == '1') {
        b = false;
        break;
      }
    }
    if (b) {
      ans.push_back(lamp);
    }
  }
  if (ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < (n / 6); j++) {
        cout << ans[i];
      }
      cout << ans[i].substr(0, n % 6) << endl;
    }
  }
}