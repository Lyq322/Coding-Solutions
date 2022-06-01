#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

ifstream fin;

int n, m;
int cows[100000];
vector<vector<pair<int,int>>> wormholes;
int widths[100000];
bool visited[100000];
set<int> s1;
set<int> s2;
int min_width;

void dfs(int pos) {
  //cout << "pos " << pos << endl;
  for (int i = 0; i < wormholes[pos].size(); i++) {
    if (!visited[wormholes[pos][i].first] && wormholes[pos][i].second >= min_width) {
      visited[wormholes[pos][i].first] = true;
      s1.insert(wormholes[pos][i].first);
      //cout << wormholes[pos][i].first << ' ';
      s2.insert(cows[wormholes[pos][i].first]);
      dfs(wormholes[pos][i].first);
    }
  }
}

bool check() {
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      s1.insert(i);
      //cout << i << ' ';
      s2.insert(cows[i]);
      dfs(i);
      //cout << "end" << endl;
      if (s1 != s2) {
        //cout << "different\n";
        return false;
      }
      //cout << "same\n";
      s1.clear();
      s2.clear();
    }
  }
  return true;
}

int main() {
  fin.open("wormhole.in");
  fin >> n >> m;
  bool sorted = true;
  int a;
  for (int i = 0; i < n; i++) {
    fin >> a;
    cows[i] = a - 1;
    if (cows[i] != i) {
      sorted = false;
    }
    //reversed[cows[i]] = i;
  }
  /*for (int i = 0; i < n; i++) {
    cout << reversed[i] << endl;
  }*/
  if (sorted) {
    cout << -1 << endl;
  }
  else {
    for (int i = 0; i < m; i++) {
      wormholes.push_back({});
    }
    int a, b, w;
    for (int i = 0; i < m; i++) {
      fin >> a >> b >> w;
      wormholes[a - 1].push_back({b - 1, w});
      wormholes[b - 1].push_back({a - 1, w});
      widths[i] = w;
    }
    sort(widths, widths + m);
    min_width = widths[0];
    //cout << widths[0] << endl;
    //cout << check();
    for (int i = 0; i < m; i++) {
      min_width = widths[i];
      cout << check() << endl;
    }
    int L = 0;
    int R = m - 1;
    int M;
    while (L < R) {
      M = (L + R) / 2;
      min_width = widths[M];
      if (check()) {
        L = M + 1;
      }
      else {
        R = M;
      }
    }
    cout << L << ' ' << R << ' ' << M << endl;
    cout << widths[L - 1] << endl;
  }
}