#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef pair<int, int> pii;

const int max_n = 100001;
const int max_k = 200001;

int n, k;
int cows[max_n];
int visited[max_n] = {0};
int answer[max_n];
set<int> moves[max_n];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cows[i] = i;
    moves[i].insert(i);
  }
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    moves[cows[a]].insert(b);
    moves[cows[b]].insert(a);
    int temp = cows[a];
    cows[a] = cows[b];
    cows[b] = temp;
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      int pos = i;
      set<int> ans;
      vector<int> visited_pos;
      while (true) {
        if (visited[pos] == 1) {
          break;
        }
        for (auto it = moves[pos].begin(); it != moves[pos].end(); it++) {
          ans.insert(*it);
        }
        visited[pos] = 1;
        visited_pos.push_back(pos);
        pos = cows[pos];
      }
      for (int i = 0; i < visited_pos.size(); i++) {
        answer[visited_pos[i]] = ans.size();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << answer[i] << endl;
  }
} 