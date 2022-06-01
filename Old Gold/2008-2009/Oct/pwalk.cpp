#include <iostream>

using namespace std;

int N, Q;
int** path;
int length;
int start, finish;
bool found;
int* mark;

void dfs(int pos) {
  int p;
  if (found) {
    return;
  }
  if (pos == finish) {
    cout << length << endl;
    found = true;
    return;
  }
  for (int i = 1; i < N + 1; i++) {
    p = path[pos][i];
    if (p != 0 && mark[i] != 1) {
      length = length + p;
      mark[i] = 1;
      dfs(i);
      mark[i] = 0;
      length = length - p;
    }
  }
}

int main() {
  cin >> N >> Q;
  path = new int*[N + 1];
  mark = new int[N + 1];
  int a, b, l;
  for (int i = 0; i < N + 1; i++) {
    path[i] = new int[N + 1];
    for (int j = 0; j < N + 1; j++) {
      path[i][j] = 0;
    }
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b >> l;
    path[a][b] = l;
    path[b][a] = l;
  }
  for (int i = 0; i < Q; i++) {
    cin >> start >> finish; 
    for (int i = 0; i < N + 1; i++) {
      mark[i] = 0;
    }
    mark[start] = 1;
    length = 0;
    found = false;
    dfs(start);
  }
}