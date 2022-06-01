#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin;
ofstream fout;

int n, m;
vector<pair<int, int>> cows;
int cereal[100000] = {0};
vector<int> answer;

int main() {
  fin.open("cereal.in");
  fout.open("cereal.out");
  fin >> n >> m;
  int a, b;
  for (int i = 0; i < n; i++) {
    fin >> a >> b;
    cows.push_back({a - 1, b - 1});
  }
  for (int i = 0; i < m; i++) {
    cereal[i] = -1;
  }
  reverse(cows.begin(), cows.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    pair<int, int> cur = cows[i];
    int j = i;
    int pos = cur.first;
    while (true) {
      if (cereal[pos] == -1) {
        ans++;
        cereal[pos] = j;
        break;
      }
      else if (cereal[pos] < j) {
        int temp = cereal[pos];
        cereal[pos] = j;
        if (cows[temp].first == pos) {
          j = temp;
          pos = cows[j].second;
        }
        else {
          break;
        }
      }
      else {
        break;
      }
    }
    answer.push_back(ans);
  }
  for (int i = answer.size() - 1; i > -1; i--) {
    fout << answer[i] << endl;
  }
} 