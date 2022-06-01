#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string s;
string e;
vector<string> dict;
vector<int> visited;
queue<pair<string, int>> bfs;

bool check(string a, string b) {
  int different = 0;
  for (int i = 0; i < a.length(); i++) {
    if (different > 1) {
      return false;
    }
    if (a[i] != b[i]) {
      different++;
    }
  }
  if (different != 1) {
    return false;
  }
  return true;
}

int main() {
  cin >> s >> e;
  string str;
  while (!cin.eof()) {
    cin >> str;
    if (str.length() == s.length()) {
      dict.push_back(str);
      visited.push_back(0);
    }
  }
  bfs.push({s, 0});
  while (!bfs.empty()) {
    str = bfs.front().first;
    int moves = bfs.front().second;
    bfs.pop();
    if (str == e) {
      cout << moves << endl;
      break;
    }
    for (int i = 0; i < dict.size(); i++) {
      if (check(dict[i], str) && visited[i] == 0) {
        visited[i] = 1;
        bfs.push({dict[i], moves + 1});
      }
    }
  }
}