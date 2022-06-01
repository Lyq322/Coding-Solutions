#include <iostream>

using namespace std;

int N;
string dna[7];
int visited[7] = {0};
int merge_string[7][7];
int ans = -1;

string merge(string a, string b) {
  for (int i = 0; i < a.length(); i++) {
    if (a.at(i) == b.at(0) && a.length() - i <= b.length()) {
      bool check = true;
      int length = 1;
      for (int j = 1; j < b.length(); j++) {
        if (i + j == a.length()) {
          break;
        }
        if (a.at(i + j) != b.at(j)) {
          check = false;
          break;
        }
        length = j + 1;
      }
      if (check) {
        return a.substr(0, a.length() - length) + b;
      }
    }
  }
  return a + b;
}

void dfs(int pos, string str, int index) {
  //cout << pos << ' ' << str << endl;
  if (index == N) {
    if (ans == -1 || str.length() < ans) {
      //cout << "smallest" << endl;
      ans = str.length();
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    if (visited[i] == 0 && i != pos) {
      visited[i] = 1;
      dfs(i, merge(str, dna[i]), index + 1);
      visited[i] = 0;
    }
  }
}

int main() {
  cin >> N;
  cin.ignore();
  for (int i = 0; i < N; i++) {
    getline(cin, dna[i]);
  }
  //cout << merge("GAAAAA", "AAAAAT");
  //cout << merge("TGAAAAAT", "GAAAAA") << endl;
  for (int i = 0; i < N; i++) {
    visited[i] = 1;
    dfs(i, dna[i], 1);
    visited[i] = 0;
  }
  cout << ans << endl;
} 