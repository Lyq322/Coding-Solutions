#include <iostream>
#include <queue>

using namespace std;
/*
10
5 4 9 2 6 7 2 6 1 3*/
int n;
int cows[100001];
int fr[100001] = {0};
queue<int> q;
int ans;

int main() {
  cin >> n;
  ans = n;
  for (int i = 0; i < n; i++) {
    cin >> cows[i + 1];
    fr[cows[i + 1]]++;
  }
  for (int i = 1; i <= n; i++) {
    //cout << fr[i] << ' ';
    if (fr[i] == 0) {
      ans--;
      q.push(i);
      //cout << "push " << i << endl;
    }
  }
  cout << endl;
  while (!q.empty()) {
    int pos = q.front();
    //cout << "pos " << pos << endl;
    q.pop();
    fr[cows[pos]]--;
    if (fr[cows[pos]] == 0) {
      ans--;
      q.push(cows[pos]);
      //cout << "push " << cows[pos] << endl;
    }
  }
  cout << ans << endl;
}