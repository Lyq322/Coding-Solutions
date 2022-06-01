#include <iostream>
#include <vector>

using namespace std;

//typedef pair<int, int> pii;

int N;
int* mountains;
//vector<pii> peaks;
vector<int> peaks;
int ans = 0;

int main() {
  cin >> N;
  mountains = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> mountains[i];
  }
  int c = true;
  for (int i = 0; i < N - 1; i++) {
    if (c) {
      if (mountains[i] > mountains[i + 1]) {
        c = false;
        //peaks.push_back({0,i});
        peaks.push_back(i);
      }
    }
    else {
      if (mountains[i] < mountains[i + 1]) {
        c = true;
      }
    }
  }
  if (c) {
    peaks.push_back(N - 1);
  }
  /*
  c = true;
  int a = peaks.size() - 1;
  for (int i = N - 1; i > 0; i--) {
    if (c) {
      if (mountains[i] > mountains[i - 1]) {
        c = false;
        peaks[a].first = i;
        a--;
      }
    }
    else {
      if (mountains[i] < mountains[i - 1]) {
        c = true;
      }
    }
  }
  if (c) {
    peaks[a].first = 0;
  }
  for (int i = 0; i < peaks.size(); i++) {
    cout << peaks[i].first << ' ' << peaks[i].second << endl;
  }
  */
  int l, r;
  for (int i = 0; i < peaks.size(); i++) {
    //cout << peaks[i] << endl;
    l = 0;
    r = N - 1;
    for (int j = peaks[i]; j < N - 1; j++) {
      if (mountains[j] < mountains[j + 1]) {
        r = j;
        break;
      }
    }
    for (int j = peaks[i]; j > 0; j--) {
      if (mountains[j] < mountains[j - 1]) {
        l = j;
        break;
      }
    }
    //cout << "l " << l << ' ' << "r " << r << endl;
    if (ans < r - l + 1) {
      ans = r - l + 1;
    }
  }
  cout << ans << endl;
}