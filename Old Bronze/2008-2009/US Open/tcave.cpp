#include <iostream>

using namespace std;

int P, NS, T;
int** cave;
int* path;

void find(int pos, int depth) {
  //cout << "pos " << pos << endl;
  //for (int i = 0; i < depth; i++) {
    //cout << path[i] << ' ';
  //}
  //cout << endl;
  if (pos == T) {
    cout << depth + 1 << endl;
    for (int i = 0; i < depth; i++) {
      cout << path[i] << endl;
    }
    cout << pos << endl;
    return;
  }
  if (cave[pos][0] == 0) {
    return;
  }
  int left = cave[pos][0];
  int right = cave[pos][1];
  path[depth] = pos;
  find(left, depth + 1);
  find(right, depth + 1);
  return;
}

int main() {
  cin >> P >> NS >> T;
  cave = new int*[P + 1];
  path = new int[P];
  int a, b, c;
  for (int i = 0; i < P + 1; i++) {
    cave[i] = new int[2];
    cave[i][0] = 0;
    cave[i][1] = 0;
  }
  for (int i = 0; i < NS; i++) {
    cin >> a >> b >> c;
    cave[a][0] = b;
    cave[a][1] = c;
  }
  find(1, 0);
  //cout << "end\n";
}