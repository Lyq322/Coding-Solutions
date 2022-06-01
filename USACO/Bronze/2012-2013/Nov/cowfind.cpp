#include <iostream>
#include <vector>

using namespace std;

string s;

int main() {
  cin >> s;
  vector<int> backLegs;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s.at(i) == '(' && s.at(i + 1) == '(') {
      backLegs.push_back(i);
    } 
  }
  vector<int> frontLegs;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s.at(i) == ')' && s.at(i + 1) == ')') {
      frontLegs.push_back(i);
    }
  }
  int i = 0;
  int j = 0;
  int ans = 0;
  while (i < backLegs.size() && j < frontLegs.size()) {
    if (backLegs[i] < frontLegs[j]) {
      ans += frontLegs.size() - j;
      i++;
    }
    else {
      j++;
    }
  }
  cout << ans << endl;
}