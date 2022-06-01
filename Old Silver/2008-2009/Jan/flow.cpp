#include <iostream>

using namespace std;

int n;
int k = 52;
char c1, c2;
int flow;
int index1, index2;
int rivers[52][52] = {{0}};

char tochar(int a) {
  char c;
  if (a > 25) {
    c = char(a - 26 + 97);
  }
  else {
    c = char(a + 65);
  }
  return c;
}

int child(int pos) {
  int num = 0;
  for (int i = 0; i < k; i++) {
    if (rivers[pos][i] > 0) {
      num++;
    }
  }
  return num;
}

void cut(int pos) {
  for (int i = 0; i < k; i++) {
    if (rivers[pos][i] != 0) {
      cut(i);
      if (child(i) == 0 && i != 25) {
        for (int j = 0; j < k; j++) {
          rivers[j][i] = 0;
        }
      }
    }
  }
}

void reduce(int pos) {
  /*
  cout << "pos " << pos << endl;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (rivers[i][j] > 0) {
        if (i > 25) {
          c1 = char(i - 26 + 97);
        }
        else {
          c1 = char(i + 65);
        }
        if (j > 25) {
          c2 = char(j - 26 + 97);
        }
        else {
          c2 = char(j + 65);
        }
        cout << c1 << ' ' << c2 << ' ' << rivers[i][j] << endl;
      }
    }
  }
  cin.ignore();*/
  // If only one parent and only one child, then reduce
  int parent = 0;
  int p_pos;
  int child = 0;
  int c_pos;
  for (int j = 0; j < k; j++) {
    if (rivers[j][pos] > 0) {
      parent++;
      p_pos = j;
      if (parent >= 2) {
        break;
      }
    }
    if (rivers[pos][j] > 0) {
      reduce(j);
    }
    if (rivers[pos][j] > 0) {
      child++;
      c_pos = j;
    }
  }
  //cout << "pos " << pos << ' ' << child << ' ' << parent << endl;
  if (child == 1 && parent == 1) {
    rivers[p_pos][c_pos] += min(rivers[p_pos][pos], rivers[pos][c_pos]);
    rivers[p_pos][pos] = 0;
    rivers[pos][c_pos] = 0;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c1 >> c2 >> flow;
    if ('a' <= c1 && c1 <= 'z') {
      index1 = c1 - 'a' + 26;
    }
    else {
      index1 = c1 - 'A';
    }
    if ('a' <= c2 && c2 <= 'z') {
      index2 = c2 - 'a' + 26;
    }
    else {
      index2 = c2 - 'A';
    }
    rivers[index1][index2] += flow;
    // A, B, ..., Z, a, b, ..., z
    // A = 0, Z = 26
  }
  for (int i = 0; i < k; i++) {
    cut(i);
  }
  for (int i = 0; i < k; i++) {
    reduce(i);
  }
  for (int i = 0; i < k; i++) {
    reduce(i);
  }
}