#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, b;
int tiles[250];
bool visited[250][250];
pii boots[250];
int ans = -1;

void graph(int pos, int boot) {
  if (boot >= b) {
    return;
  }
  int distance = boots[boot].second;
  int height = boots[boot].first;
  vector<int> possible;
  bool finish = false;
  for (int i = pos + 1; i <= distance + pos; i++) {
    if (i >= n) {
      finish = true;
      break;
    }
    if (tiles[i] <= height) {
      possible.push_back(i);
    }
  }
  //cout << pos << ' ' << boot << ' ' << discard << endl;
  for (int i = 0; i < possible.size(); i++) {
    //cout << possible[i] << ' ';
  }
  //cout << endl;
  //cin.ignore();
  if (finish) {
    //cout << "finished\n";
    if (ans == -1 || ans > boot) {
      ans = boot;
    }
  }
  else {
    for (int i = 0; i < possible.size(); i++) {
      if (!visited[possible[i]][boot]) {
        visited[possible[i]][boot] = true;
        graph(possible[i], boot);
      }
      else if (!visited[possible[i]][boot + 1]) {
        visited[possible[i]][boot + 1] = true;
        graph(possible[i], boot + 1);
      }
    }
    if (!visited[pos][boot + 1]) {
      visited[pos][boot + 1] = true;
      graph(pos, boot + 1);
    }
  }
}

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> tiles[i];
  }
  int a, c;
  for (int i = 0; i < b; i++) {
    cin >> a >> c;
    boots[i].first = a;
    boots[i].second = c;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < b; j++) {
      visited[i][j] = false;
    }
  }
  graph(0, 0);
  cout << ans << endl;
}