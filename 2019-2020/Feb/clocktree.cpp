#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

int n;
int clocks[2500];
bool visited[2500] = {0};
vector<vector<int>> adj;

int dfs(int pos) {
  //cout << "pos " << pos << endl;
  int value = 0;
  for (int i = 0; i < adj[pos].size(); i++) {
    int next = adj[pos][i];
    if (!visited[next]) {
      visited[next] = true;
      value += dfs(next);
    }
  }
  return (12 - clocks[pos] - value) % 12; 
}

int main() {
  fin.open("clock.in");
  fout.open("clock.out");
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> clocks[i];
    adj.push_back({});
  }
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    fin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  int value;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[j] = false;
    }
    visited[i] = true;
    value = dfs(i);
    if (value == 0 || value == -1 || value == 11) {
      ans++;
    }
  }
  cout << ans << endl;
}