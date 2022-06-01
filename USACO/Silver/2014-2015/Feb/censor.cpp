#include <iostream>

using namespace std;

string s, t, result = "";

int main() {
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    result += s[i];
    if (result.size() >= t.size() && result.substr(result.size() - t.size(), t.size()) == t) {
      result.resize(result.size() - t.size());
    }
  }
  cout << result << endl;
}