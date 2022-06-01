#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char *letters;
int *ans;

void combination (int pos) {
  /*
  for (int i = 0; i < pos; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';*/
  if (pos == L) {
    //cout << "tuna" << endl;
    char c;
    int vowel = 0;
    for (int i = 0; i < L; i++) {
      c = letters[ans[i]];
      //cout << "c " << c << endl;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowel++;
      }
    }
    if (vowel > 0 && L - vowel > 1) {
      for (int i = 0; i < L; i++) {
        cout << letters[ans[i]];
      }
      cout << '\n';
    }
    return;
  }
  if (ans[pos - 1] + 1 > C) {
    return;
  }
  for (int i = ans[pos - 1] + 1; i < C; i++) {
    //cout << "i " << i << endl;
    ans[pos] = i;
    combination(pos + 1);
  }
}

int main() {
  cin >> L >> C;
  letters = new char[C];
  for (int i = 0; i < C; i++) {
    cin >> letters[i];
  }
  sort(letters, letters + C);
  ans = new int[L];
  for (int i = 0; i < C; i++) {
    ans[0] = i;
    combination(1);
  }
}