#include <iostream>
#include <algorithm>

using namespace std;

int N, M, C;
int cow[100000];

bool check(int time) {
  //cout << "time " << time << endl;
  int ferry = 1;
  int start = cow[0];
  int start_c = 0;
  for (int i = 0; i < N; i++) {
    /*
    cout << "i " << i << endl;
    cout << "ferry " << ferry << endl;
    cout << "start " << start << endl;
    cout << "c " << c << endl;
    cout << "cow[i] " << cow[i] << endl;*/
    if (cow[i] - start > time || i - start_c + 1 > C) {
      //cout << "plus\n";
      ferry++;
      start = cow[i];
      start_c = i;
      if (ferry > M) {
        return false;
      }
    }
  }
  //cout << ferry << endl;
  if (ferry > M) {
    return false;
  }
  return true;
}

void bs(int l, int r) {
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (!check(m - 1) && check(m)) {
      break;
    }
    if (check(m)) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  cout << m << endl;
}

int main() {
  cin >> N >> M >> C;
  for (int i = 0; i < N; i++) {
    cin >> cow[i];
  }
  sort(cow, cow + N);
  bs(1,1000000000);
  //cout << check(4) << endl;
}