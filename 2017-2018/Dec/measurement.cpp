#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct Entry {
  int day;
  int id;
  int milk;
};

int N, G;
map<int, int> cows;
map<int, int> leaderboard;
set<int> c;
Entry change[100000];
int ans = 0;

bool comp(Entry a, Entry b) {
  return a.day < b.day;
}

int main() {
  cin >> N >> G;
  for (int i = 0; i < N; i++) {
    cin >> change[i].day >> change[i].id >> change[i].milk;
  }
  sort(change, change + N, comp);
  for (int i = 0; i < N; i++) {
    c.insert(change[i].id);
    cout << change[i].id << ' ' << change[i].milk << endl;
  }
  int leader = 0;
  int times = c.size();
  leaderboard[0] = c.size();
  bool n;
  for (int i = 0; i < N; i++) {
    n = false;
    if (leaderboard.rbegin() -> first == cows[change[i].id] && leaderboard.rbegin() -> second == 1 && leaderboard.rbegin() -> first != 0) {
      n = true;
    }
    if (cows.find(change[i].id) == cows.end()) {
      leaderboard[0] -= 1;
      if (leaderboard[0] == 0) {
        leaderboard.erase(0);
      }
      cows[change[i].id] = change[i].milk;
    }
    else {
      leaderboard[cows[change[i].id]] -= 1;
      if (leaderboard[cows[change[i].id]] == 0) {
        leaderboard.erase(cows[change[i].id]);
      }
      cows[change[i].id] += change[i].milk;
    }
    cout << "i " << i << endl;
    if (leaderboard.find(cows[change[i].id]) == leaderboard.end()) {
      leaderboard[cows[change[i].id]] = 1;
    }
    else {
      leaderboard[cows[change[i].id]] += 1;
    }
    if (leaderboard.rbegin() -> first == cows[change[i].id] && leaderboard.rbegin() -> second == 1 && n == true) {
      leader = leaderboard.rbegin() -> first;
      times = 1;
      continue;
    }
    if (leaderboard.rbegin() -> first != leader) {
      cout << "change1\n";
      ans++;
      leader = leaderboard.rbegin() -> first;
      times = leaderboard.rbegin() -> second;
    }
    else if (leaderboard.rbegin() -> second != times) {
      cout << "change2\n";
      ans++;
      times = leaderboard.rbegin() -> second;
    }
    cout << "leader " << leader << " times " << times << endl;
    cout << "cows ";
    for (const auto& x : cows) {
      cout << x.first << ": " << x.second << ' ';
    }
    cout << "\n";
    cout << "leaderboard ";
    for (const auto& x : leaderboard) {
      cout << x.first << ": " << x.second << ' ';
    }
    cout << "\n"; 
  }
  cout << ans << endl;
}