#include <iostream>

using namespace std;

//---------GLOBAL VARIABLES--------
int n, m;
int adj_matrix_forward[100][100] = {{0}};
int adj_matrix_backward[100][100] = {{0}};
int visited[100] = {0};
int rounds = 0;
int win, lose;
int ans = 0;

//------------FUNCTIONS-------------
int depth_first_search(int row, int matrix[][100]) {
  for (int i = 0; i < n; i++) {
    if (matrix[row][i] == 1 && visited[i] == 0) {
      rounds++;
      visited[i] = 1;
      depth_first_search(i, matrix);
    }
  }
}

int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj_matrix_forward[a - 1][b - 1] = 1;
    adj_matrix_backward[b - 1][a - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    win = 0;
    lose = 0;
    rounds = 0;
    for (int j = 0; j < n; j++) {
      visited[j] = 0;
    }
    win = depth_first_search(i, adj_matrix_forward);
    rounds = 0;
    for (int j = 0; j < n; j++) {
      visited[j] = 0;
    }
    lose = depth_first_search(i, adj_matrix_backward);
    if (win + lose == n - 1) {
      ans++;
    }
  }
  cout << ans << endl;
}