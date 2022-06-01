#include <iostream>
#include <cmath>

int N, M;
int** cows;
int** seats;
long int closest;
int mini;
int* visited;

using namespace std;

long int distance(int x1, int y1, int x2, int y2) {
  long int a = pow((x1-x2), 2);
  long int b = pow((y1-y2), 2);
  //cout << "a " << a << endl;
  //cout << "b " << b << endl;
  return a + b;
}

int main() {
  cin >> N >> M;
  cows = new int*[N];
  visited = new int[N];
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
    cows[i] = new int[2];
    cin >> cows[i][0] >> cows[i][1];
  }
  seats = new int*[M];
  for (int i = 0; i < M; i++) {
    seats[i] = new int[2];
    cin >> seats[i][0] >> seats[i][1];
  }
  for (int i = 0; i < M; i++) {
    //cout << "i " << i << endl;
    closest = -1;
    for (int j = 0; j < N; j++) {
      //cout << cows[j][0] << ' ' << cows[j][1] << ' ' << seats[i][0] << ' ' << seats[i][1] << endl;
      long int d = distance(cows[j][0], cows[j][1], seats[i][0], seats[i][1]);
      //cout << "d " << d << endl;
      if (visited[j] == 0) {
        if (closest == -1) {
          closest = d;
          mini = j;
        }
        else if (closest > d) {
          closest = d;
          mini = j;
        }
      }
    }
    visited[mini] = 1;
    //cout << mini << endl;
  }
  bool n = true;
  for (int i = 0; i < N; i++) {
    if (visited[i] == 0) {
      cout << i+1 << endl;
      n = false;
    }
  }
  if (n) {
    cout << 0 << endl;
  }
}