#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int n, m;
vector<vector<pair<int,char>>> connections;
int visited[100000];
bool violation = false;
int ans = 0;

int main() {
  cin >> n >> m;
  char c;
  int a, b;
  for (int i = 0; i < n; i++) {
    connections.push_back({});
  }
  for (int i = 0; i < m; i++) {
    cin >> c >> a >> b;
    a--;
    b--;
    connections[a].push_back({b, c});
    connections[b].push_back({a, c});
  }
  for (int i = 0; i < n; i++) {
    if (violation) {
      break;
    }
    if (visited[i] == 0) {
      cout << i << endl;
      ans++;
      stack<int> s;
      s.push(i);
      visited[i] = 1;
      while (!s.empty()) {
        if (violation) {
          break;
        }
        int node = s.top();
        s.pop();
        for (int j = 0; j < connections[node].size(); j++) {
          int next = connections[node][j].first;
          if (connections[node][j].second == 'S') {
            if (visited[next] == 0) {
              visited[next] = visited[node];
              s.push(next);
            }
            else if (visited[next] != visited[node]) {
              violation = true;
              break;
            }
          }
          else { 
            if (visited[next] == 0) {
              if (visited[node] == 1) {
                visited[next] = 2;
              }
              else {
                visited[next] = 1;
              }
              s.push(next);
            }
            else if (visited[next] == visited[node]) {
              violation = true;
              break;
            }
          }
        }
      }
    }
  }
  if (violation) {
    cout << 0 << endl;
  }
  else {
    cout << 1;
    for (int i = 0; i < ans; i++) {
      cout << 0;
    }
    cout << endl;
  }
} 

/*
11 10
S 1 9
S 1 5
D 1 4
D 4 5
D 3 4
S 8 6
D 2 6
D 2 8
S 2 7
D 10 11
*/