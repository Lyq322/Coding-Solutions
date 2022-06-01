#include <iostream>

using namespace std;

int N, K;
int answer = 0;

// Holsteins, Jerseys, or Guernseys

void solve(int pos, char** constraints, int ans[]) {
  /*
  cout << "solve\n";
  for (int i = 0; i < pos; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << constraints[i][j] << ' ';
    }
    cout << '\n';
  } */
  if (pos == N) {
    answer++;
    return;
  }
  bool possible[3];
  possible[0] = true;
  possible[1] = true;
  possible[2] = true;
  for (int i = 0; i < pos; i++) {
    if (constraints[pos][i] == 'S') {
      if (ans[i] == 0) {
        possible[1] = false;
        possible[2] = false;
      }
      else if (ans[i] == 1) {
        possible[0] = false;
        possible[2] = false;
      }
      else {
        possible[0] = false;
        possible[1] = false;
      }
    }
    else if (constraints[pos][i] == 'D') {
      if (ans[i] == 0) {
        //cout << "tuna1\n";
        possible[0] = false;
      }
      else if (ans[i] == 1) {
        //cout << "tuna2\n";
        possible[1] = false;
      }
      else {
        //cout << "tuna3\n";
        possible[2] = false;
      }
    }
    /*
    for (int j = 0; j < 3; j++) {
      if (possible[j]) {
        cout << "True\n";
      }
      else {
        cout << "False\n";
      }
    }*/
  }
  for (int j = 0; j < 3; j++) {
    //cout << possible[j] << '\n';
    if (possible[j]) {
      ans[pos] = j;
      solve(pos + 1, constraints, ans);
    }
  }
  return;
}

int main() {
  cin >> N >> K;
  char **constraints;
  constraints = new char*[N];
  for (int i = 0; i < N; i++) {
    constraints[i] = new char[N];
  }
  char c;
  int a, b;
  for (int j = 0; j < N; j++) {
    for (int k = 0; k < N; k++) {
      constraints[j][k] = ' ';
    }
  }
  for (int i = 0; i < K; i++) {
    cin >> c >> a >> b;
    constraints[a - 1][b - 1] = c;
    constraints[b - 1][a - 1] = c;
  }
  int ans[N];
  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << constraints[i][j] << ' ';
    }
    cout << '\n';
  }*/
  solve(0, constraints, ans);
  cout << answer << '\n';
}