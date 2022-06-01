#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<string> adj[1000];
int* a;
int index;

void convert(vector<int> coef) {
  a = new int[index];
  int b = K - 1;
  for (int i = index - 1; i > -1; i--) {
    a[index - i - 1] = b / coef[i];
    b = b % coef[i];
  }
}

bool comp(int b1[], int b2[]) {
  for (int i = 0; i < index; i++) {
    if (b1[i] > b2[i]) {
      return true;
    }
    else if (b1[i] < b2[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> N >> K;
  string s;
  vector<string> cows[N];
  vector<int> coef;
  for (int i = 0; i < N; i++) {
    cows[i] = {};
  }
  for (int i = 0; i < N; i++) {
    cin >> s;
    index = 0;
    while (s != "cow.") {
      if (s == "Farmer" || s == "John" || s == "has" || s == "no") {
        cin >> s;
        continue;
      }
      cows[i].push_back(s);
      bool b = false;
      for (int j = 0; j < adj[index].size(); j++) {
        if (adj[index][j] == s) {
          b = true;
          break;
        }
      }
      if (!b) {
        adj[index].push_back(s);
      }
      cin >> s;
      index++;
    }
  }
  int no_cow[N][index];
  int t = 1;
  coef.push_back(1);
  for (int i = index - 1; i > -1; i--) {
    sort(adj[i].begin(), adj[i].end());
    t = t * adj[i].size();
    coef.push_back(t);
  }
  convert(coef);
  for (int k = 0; k < N; k++) {
    for (int l = 0; l < cows[k].size(); l++) {
      for (int j = 0; j < adj[l].size(); j++) {
          if (adj[l][j] == cows[k][l]) {
            no_cow[k][l] = j;
          }
        }
    }
  }
  t = 0;
  for (int i = 0; i < N; i++) {
    if (comp(a, no_cow[i])) {
      t++;
    }
  }
  while (t != 0) {
    for (int j = index - 1; j > -1; j--) {
      a[j]++;
      if (a[j] == adj[j].size()) {
        a[j] = 0;
      }
      else {
        break;
      }
    }
    bool b = true;
    for (int j = 0; j < N; j++) {
      bool c = true;
      for (int i = 0; i < index; i++) {
        if (no_cow[j][i] != a[i]) {
          c = false;
          break;
        }
      }
      if (c) {
        b = false;
        break;
      }
    }
    if (b) {
      t--;
    }
  }
  for (int i = 0; i < index; i++) {
    int n = a[i];
    cout << adj[i][n] << ' ';
  }
  cout << endl;
}