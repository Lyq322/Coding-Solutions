#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

int n, s, e;
vector<vector<pii>> events;
int rolls[9] = {0};
int ans = 0;

bool check(int current) {
  int left = 0;
  int need = 0;
  for (int i = 0; i < s; i++) {
    left += rolls[i];
  }
  left = n - left;
  for (int i = 0; i < events[current].size(); i++) {
    int a = events[current][i].first;
    int b = a - rolls[events[current][i].second];
    if (b < 0) {
      b = 0;
    }
    need += b;
  }
  if (need > left) {
    return false;
  }
  return true;
}

void dfs(int pos) {
  bool b = true;
  for (int i = 0; i < e; i++) {
    if (check(i)) {
      b = false;
      break;
    }
  }
  if (b) {
    return;
  }
  if (pos == n) {
    for (int j = 0; j < e; j++) {
      b = true;
      for (int i = 0; i < events[j].size(); i++) {
        if (events[j][i].first > rolls[events[j][i].second]) {
          b = false;
          break;
        }
      }
      if (b) {
        ans++;
        return;
      }
    }
    return;
  }
  for (int i = 1; i <= s; i++) {
    rolls[i]++;
    dfs(pos + 1);
    rolls[i]--;
  }
}

int main() {
  cin >> n >> s >> e;
  string str;
  for (int i = 0; i < e; i++) {
    events.push_back({});
  }
  for (int i = 0; i < e; i++) {
    cin >> str;
    int begin = 0;
    int index = -1;
    for (int j = 0; j < str.size(); j++) {
      if (str[j] == 'x') {
        int a = stoi(str.substr(begin, j - begin));
        events[i].push_back({a, 0});
        index++;
        begin = j + 1;
      }
      else if (str[j] == '+') {
        int a = stoi(str.substr(begin, j - begin));
        events[i][index].second = a;
        begin = j + 1;
      }
    }
    events[i][index].second = stoi(str.substr(begin, str.size() - begin));
  }
  dfs(0);
  cout << ans << endl;
} 