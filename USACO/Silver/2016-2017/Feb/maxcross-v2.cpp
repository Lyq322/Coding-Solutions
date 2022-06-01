#include <iostream>

using namespace std;

int N, K, B;
int a[100001] = {0};
//int road[100001];
int ans = -1;

int main() {
  cin >> N >> K >> B;
  int pos;
  for (int i = 0; i < B; i++) {
    cin >> pos;
    a[pos] = 1;
  }
  int t = 0;
  for (int i = 1; i < K + 1; i++) {
    if (a[i] == 1) {
      t++;
    }
  }
  for (int i = 1; i < N - K + 1; i++) {
    //cout << "i " << i << endl;
    //cout << a[i] << ' ' << a[i+K] << endl; 
    if (a[i] == 1) {
      t--;
    }
    if (a[i + K] == 1) {
      t++;
    }
    cout << t << endl;
    if (ans == -1 || ans > t) {
      ans = t;
    }
  }
  cout << endl;
  cout << ans << endl;
}