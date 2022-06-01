#include <iostream>

using namespace std;

int N;
int hoof[500000];
int paper[500000];
int scissor[500000];
int ans = 0;

int main() {
  cin >> N;
  char c;
  int h = 0;
  int p = 0;
  int s = 0;
  for (int i = 0; i < N; i++) {
    cin >> c;
    if (c == 'H') {
      p++;
    }
    else if (c == 'P') {
      s++;
    }
    else {
      h++;
    }
    hoof[i] = h;
    paper[i] = p;
    scissor[i] = s;
  }
  for (int i = 0; i < N; i++) {
    ans = max(ans, paper[i] + scissor[N - 1] - scissor[i]);
    ans = max(ans, hoof[i] + scissor[N - 1] - scissor[i]);
    ans = max(ans, scissor[i] + paper[N - 1] - paper[i]);
    ans = max(ans, hoof[i] + paper[N - 1] - paper[i]);
    ans = max(ans, paper[i] + hoof[N - 1] - hoof[i]);
    ans = max(ans, scissor[i] + hoof[N - 1] - hoof[i]);
  }
  cout << ans << endl;
}