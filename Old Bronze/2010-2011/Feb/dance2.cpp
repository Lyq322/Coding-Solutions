#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N;
  cin >> N;
  int len;
  string str;
  for (int i = 0; i < N; i++) {
    cin >> len;
    cin >> str;
    stack<char> cattle;
    for (int j = 0; j < len; j++) {
      if (cattle.empty()) {
        cattle.push(str.at(j));
      }
      else if (cattle.top() == '>' && str.at(j) == '<') {
        cattle.pop();
      }
      else {
        cattle.push(str.at(j));
      }
    }
    if (cattle.empty()) {
      cout << "legal\n";
    }
    else {
      cout << "illegal\n";
    }
  }
}