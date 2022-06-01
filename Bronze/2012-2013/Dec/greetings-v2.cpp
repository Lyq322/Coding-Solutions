#include <iostream>
#include <fstream>

using namespace std;

int N, M;
int move_a[50000];
int move_b[50000];
int ans = 0;

/*
6 6
3 R
3 L
2 L
3 L
5 R
3 L
3 R
3 L
4 R
3 R
2 L
4 L
5 R
1 L
*/
/*
5 5
3 L
3 R
2 L
3 R
2 L
3 L
3 R
4 R
3 L
2 L
*/

bool opp(int i, int j) {
  if (move_a[i] > 0 && move_b[j] < 0) {
    return true;
  }
  else if (move_a[i] < 0 && move_b[j] > 0) {
    return true;
  }
  return false;
}

int main() {
  cin >> N >> M;
  int d;
  char c;
  for (int i = 0; i < N; i++) {
    cin >> d >> c;
    if (c == 'L') {
      move_a[i] = -d;
    }
    else {
      move_a[i] = d;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> d >> c;
    if (c == 'L') {
      move_b[i] = -d;
    }
    else {
      move_b[i] = d;
    }
  }
  /*
  for (int i = 0; i < N; i++) {
    cout << move_a[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < M; i++) {
    cout << move_b[i] << ' ';
  }
  cout << endl;*/
  int i = 1;
  int j = 1;
  int distance_a = 0;
  int distance_b = 0;
  int pos_a = move_a[0];
  int pos_b = move_b[0];
  bool left;
  bool equal = false;
  if (move_a[0] < 0 && move_b[0] > 0) {
    left = true;
  }
  else if (move_a[0] > 0 && move_b[0] < 0){
    left = false;
  }
  else {
    //cout << "equal\n";
    left = true;
    equal = true;
    for (int k = 0; k < N; k++) {
      if (move_a[k] != move_b[k]) {
        i = k;
        j = k;
        break;
      }
      else {
        pos_a = pos_a + move_a[k];
      }
    }
    pos_a = pos_a - move_a[0];
    pos_b = pos_a;
    cout << "pos_a " << pos_a << endl;
  }
  while (i < N || j < M) {
    cout << "i " << i << ' ' << "j " << j << endl;
    cout << pos_a << ' ' << pos_b << endl;
    if (i == N) {
      pos_b = pos_b + move_b[j];
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      else if (left && pos_a > pos_b) {
        cout << "change1\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a < pos_b) {
        cout << "change2\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        cout << "change3\n";
        ans++;
        equal = true;
      }
      j++;
    }
    else if (j == M) {
      pos_a = pos_a + move_a[i];
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      else if (left && pos_a >= pos_b) {
        cout << "change4\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a <= pos_b) {
        cout << "change5\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        cout << "change6\n";
        ans++;
        equal = true;
      }
      i++;
    }
    else {
      if (distance_a <= distance_b) {
        pos_a = pos_a + move_a[i];
        distance_a = distance_a + abs(move_a[i]);
        i++;
      }
      else {
        pos_b = pos_b + move_b[j];
        distance_b = distance_b + abs(move_b[j]);
        j++;
      }
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      if (left && pos_a > pos_b && opp(i, j)) {
        cout << "change7\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a < pos_b && opp(i, j)) {
        cout << "change8\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        if (i + 1 < N && j + 1 < N) {
          if (move_a[i + 1] == move_b[i + 1]) {
            i++;
            j++;
            continue;
          }
        }
        cout << "change9\n";
        ans++;
        equal = true;
      }
    }
  }
  cout << ans << endl;
}

/*#include <iostream>
#include <fstream>

using namespace std;

int N, M;
int move_a[50000];
int move_b[50000];
int ans = 0;

int main() {
  cin >> N >> M;
  int d;
  char c;
  for (int i = 0; i < N; i++) {
    cin >> d >> c;
    if (c == 'L') {
      move_a[i] = -d;
    }
    else {
      move_a[i] = d;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> d >> c;
    if (c == 'L') {
      move_b[i] = -d;
    }
    else {
      move_b[i] = d;
    }
  }
  int i = 0;
  int j = 0;
  int distance_a = 0;
  int distance_b = 0;
  int pos_a = 0;
  int pos_b = 0;
  bool left;
  bool equal = false;
  
  if (N == 0) {
    if (move_b[0] < 0) {
      left = false;
    }
    else {
      left = true;
    }
  }
  else if (M == 0) {
    if (move_a[0] < 0) {
      left = false;
    }
    else {
      left = true;
    }
  }
  if (move_a[0] < 0 && move_b[0] > 0) {
    left = true;
  }
  else if (move_a[0] > 0 && move_b[0] < 0){
    left = false;
  }
  else {
    left = true;
    equal = true;
  }
  while (i < N || j < M) {
    //cout << "i " << i << ' ' << "j " << j << endl;
    if (i == N) {
      pos_b = pos_b + move_b[j];
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      else if (left && pos_a > pos_b) {
        //cout << "change1\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a < pos_b) {
        //cout << "change2\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        ans++;
        equal = true;
      }
      j++;
    }
    else if (j == M) {
      pos_a = pos_a + move_a[i];
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      else if (left && pos_a >= pos_b) {
        //cout << "change3\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a <= pos_b) {
        //cout << "change4\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        ans++;
        equal = true;
      }
      i++;
    }
    else {
      if (distance_a <= distance_b) {
        pos_a = pos_a + move_a[i];
        distance_a = distance_a + abs(move_a[i]);
        i++;
      }
      else {
        pos_b = pos_b + move_b[j];
        distance_b = distance_b + abs(move_b[j]);
        j++;
      }
      if (equal) {
        equal = false;
        if (pos_a < pos_b) {
          left = true;
        }
        else {
          left = false;
        }
      }
      if (left && pos_a > pos_b) {
        //cout << "change5\n";
        left = false;
        ans++;
      }
      else if (!left && pos_a < pos_b) {
        //cout << "change6\n";
        left = true;
        ans++;
      }
      else if (pos_a == pos_b) {
        ans++;
        equal = true;
      }
    }
  }
  cout << ans << endl;
}*/