#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin;

int N;
vector<int> farm[100001];
int visited[100001] = {0};
int ans = 0;

void dfs(int pos) {
  int x = 1;
  if (pos == 1) {
    while (x <= farm[pos].size()) {
      x *= 2;
      ans++;
    }
    ans += farm[pos].size();
  }
  else {
    while (x < farm[pos].size()) {
      x *= 2;
      ans++;
    }
    ans += farm[pos].size() - 1;
  }
  for (int i = 0; i < farm[pos].size(); i++) {
    int possible = farm[pos][i];
    if (visited[possible] == 0) {
      visited[possible] = 1;
      dfs(possible);
    }
  }
}

int main() {
  cin >> N;
  int a, b;
  for (int i = 0; i < N; i++) {
    farm[i] = {};
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    farm[a].push_back(b);
    farm[b].push_back(a);
  }
  visited[1] = 1;
  dfs(1);
  cout << ans << endl;
}