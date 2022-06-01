#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int notes[N];
  for (int i = 0; i < N; i++) {
    cin >> notes[i];
  }
  int C;
  cin >> C;
  int ruminant_seventh_chord[C];
  for (int j = 0; j < C; j++) {
    cin >> ruminant_seventh_chord[j];
  }
  sort(ruminant_seventh_chord, ruminant_seventh_chord + C);
  //cout << '\n';
  bool b;
  vector<int> ans;
  for (int k = 0; k < N - C + 1; k++) {
    //cout << '\n';
    int chord[C];
    for (int l = k; l < k + C; l++) {
      chord[l - k] = notes[l];
      //cout << l - k << ' ' << chord[l - k] << '\n';
    }
    sort(chord, chord + C);
    b = true;
    for (int m = 0; m < C - 1; m++) {
      //cout << chord[m + 1] - chord[m] << ' ' << ruminant_seventh_chord[m + 1] - ruminant_seventh_chord[m] << '\n';
      if (chord[m + 1] - chord[m] != ruminant_seventh_chord[m + 1] - ruminant_seventh_chord[m]) {
        b = false;
      }
    }
    if (b == true) {
      ans.push_back(k + 1);
      //cout << k << '\n';
    }
  } 
  cout << ans.size() << '\n';
  for (int n = 0; n < ans.size(); n++) {
    cout << ans[n] << '\n';
  }
}