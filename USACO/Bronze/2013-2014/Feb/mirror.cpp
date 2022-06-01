#include <iostream>

int N, M;
char** field;
int ans = -1;
int bounce;

/*
3 4
/\\\
/\/\
\//\
*/

using namespace std;

void mirror(int x, int y, char d) {
  /*
  cin.ignore();
  cout << x << ' ' << y << ' ' << d << endl;
  cout << bounce << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << '[' << visited[i][j][0] << ", " << visited[i][j][1] << ']' << ' ';
    }
    cout << endl;
  }*/
  if (field[x][y] == '/') {
    if (d == 'U') {
      if (y == 0) {
        return;
      }
      bounce++;
      d = 'R';
      mirror(x, y - 1, d);
    }
    else if (d == 'D') {
      //cout << "tuna\n";
      if (y == M - 1) {
        return;
      }
      bounce++;
      d = 'L';
      mirror(x, y + 1, d);
    }
    else if (d == 'L') {
      if (x == 0) {
        return;
      }
      bounce++;
      d = 'D';
      mirror(x - 1, y, d);
    }
    else if (d == 'R') {
      if (x == N - 1) {
        return;
      }
      bounce++;
      d = 'U';
      mirror(x + 1, y, d);
    }
  }
  else {
    if (d == 'U') {
      if (y == M - 1) {
        return;
      }
      bounce++;
      d = 'L';
      mirror(x, y + 1, d);
    }
    else if (d == 'D') {
      if (y == 0) {
        return;
      }
      bounce++;
      d = 'R';
      mirror(x, y - 1, d);
    }
    else if (d == 'L') {
      if (x == N - 1) {
        return;
      }
      bounce++;
      d = 'U';
      mirror(x + 1, y, d);
    }
    else if (d == 'R') {
      if (x == 0) {
        return;
      }
      bounce++;
      d = 'D';
      mirror(x - 1, y, d);
    }
  }
}

int main() {
  cin >> N >> M;
  //cout << N << ' ' << M << endl;
  field = new char*[N];
  string s;
  for (int i = 0; i < N; i++) {
    field[i] = new char[M];
    //cout << "i " << i << endl;
    //cout << "s " << s << endl;
    cin >> s;
    for (int j = 0; j < M; j++) {
      field[i][j] = s.at(j);
    }
  }
  for (int i = 0; i < M; i++) {
    //cout << "new\n";
    bounce = 1;
    mirror(0, i, 'U');
    //cout << 0 << ' ' << i << ' ' << 'U' << ' ' << bounce << endl;
    if (bounce > ans) {
      ans = bounce;
    }
    //cout << "new\n";
    bounce = 1;
    mirror(N - 1, i, 'D');
    //cout << N - 1 << ' ' << i << ' ' << 'D' << ' ' << bounce << endl;
    if (bounce > ans) {
      ans = bounce;
    }
  }
  for (int i = 0; i < N; i++) {
    //cout << "new\n";
    bounce = 1;
    mirror(i, 0, 'L');
    //cout << i << ' ' << 0 << ' ' << 'L' << ' ' << bounce << endl;
    if (bounce > ans) {
      ans = bounce;
    }
    //cout << "new\n";
    bounce = 1;
    mirror(i, M - 1, 'R');
    //cout << i << ' ' << M - 1 << ' ' << 'R' << ' ' << bounce << endl;
    if (bounce > ans) {
      ans = bounce;
    }
  }
  cout << ans << endl;
}