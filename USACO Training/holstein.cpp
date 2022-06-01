#include <iostream>
#include <vector>

using namespace std;

int V, G;
int best = -1;
vector<int> answer;

void solve(int pos, int** vitamins, int ans[], int req[], int one) {
  //for (int i = 0; i < pos; i++) {
    //cout << ans[i] << ' ';
  //}
  //cout << "\n";
  //cout << "best " << best << '\n';
  //cout << "one " << one << '\n';
  if (pos == G) {
    //cout << "tuna\n";
    if (one > best && best != -1) {
      return;
    }
    int scoop[V];
    for (int k = 0; k < V; k++) {
      scoop[k] = 0;
    }
    for (int i = 0; i < G; i++) {
      //cout << "i " << i << '\n';
      if (ans[i] == 1) {
        for (int j = 0; j < V; j++) {
          //cout << "j " << j << '\n';
          scoop[j] = scoop[j] + vitamins[i][j];
        }
      }
    }
    //for (int i = 0; i < V; i++) {
      //cout << scoop[i] << ' ';
    //}
    //cout << '\n';
    for (int l = 0; l < V; l++) {
      if (scoop[l] < req[l]) {
        return;
      }
    }
    //cout << "tuna\n";
    best = one;
    answer.clear();
    for (int m = 0; m < G; m++) {
      if (ans[m] == 1) {
        answer.push_back(m + 1);
      }
    }
    return;
  }
  //cout << "zero\n";
  ans[pos] = 0;
  solve(pos + 1, vitamins, ans, req, one);
  //cout << "one\n";
  ans[pos] = 1;
  solve(pos + 1, vitamins, ans, req, one + 1);
}

int main() {
  cin >> V;
  int req[V];
  for (int i = 0; i < V; i++) {
    cin >> req[i];
  }
  cin >> G;
  int** vitamins;
  vitamins = new int*[G];
  for (int i = 0; i < G; i++) {
    vitamins[i] = new int[V];
  }
  int a;
  //vitamins[0][0] = 0;
  for (int j = 0; j < G; j++) {
    for (int k = 0; k < V; k++) {
      //cout << "k " << k << '\n';
      cin >> a;
      vitamins[j][k] = a;
      //cout << vitamins[G][V] << ' ';
    }
    //cout << '\n';
  }
  int ans[G];
  solve(0, vitamins, ans, req, 0);
  cout << best << ' ';
  for (int i = 0; i < best; i++) {
    cout << answer[i] << ' ';
  }
  cout << '\n';
}