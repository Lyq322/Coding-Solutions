#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> stands;
queue<pair<int, int>> line;
int visited[1000] = {0};
vector<int> answers;
int maximum = 0;

int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < n; i++) {
    stands.push_back({});
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    stands[a - 1].push_back(b - 1);
    stands[b - 1].push_back(a - 1);
  }
  line.push({0, 0});
  visited[0] = 1;
  while (!line.empty()) {
    int pos = line.front().first;
    int distance = line.front().second;
    line.pop();
    cout << "pos " << pos + 1 << ' ' << distance << endl;
    for (int i = 0; i < stands[pos].size(); i++) {
      int stand = stands[pos][i];
      if (visited[stand] == 0) {
        visited[stand] = 1;
        if (distance + 1 > maximum) {
          cout << "clear\n";
          answers.clear();
          cout << "push " << stand << endl;
          answers.push_back(stand);
          maximum = distance + 1;
        }
        else if (distance + 1 == maximum) {
          cout << "push " << stand << endl;
          answers.push_back(stand);
        }
        line.push({stand, distance + 1});
      }
    } 
  }
  sort(answers.begin(), answers.end());
  cout << answers[0] + 1 << ' ' << maximum << ' ' << answers.size() << endl;
}