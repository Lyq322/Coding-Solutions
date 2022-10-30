#include <iostream>
#include <set>
 
using namespace std;
 
string n;
int m, x;
set<int> split;
multiset<int> intervals;
 
int main() {
  cin >> n >> m;
  for (int i = 0; i < n.size() - 1; i++) {
    if (n.at(i + 1) != n.at(i)) {
      split.insert(i + 1);
    }
  }
  split.insert(0);
  split.insert(n.size());
  for (auto it = split.begin(); next(it) != split.end(); ++it) {
    intervals.insert(*next(it) - *it);
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    auto it1 = split.find(x);
    auto it2 = split.find(x - 1);
    if (*it1 != 0 && *it1 != n.size()) {
      if (it1 == split.end()) {
        split.insert(x);
        it1 = split.find(x);
        int a = *prev(it1);
        int b = *next(it1);
        intervals.erase(intervals.find(b - a));
        intervals.insert(b - x);
        intervals.insert(x - a);
      }
      else {
        int a = *prev(it1);
        int b = *next(it1);
        split.erase(it1);
        intervals.erase(intervals.find(b - x));
        intervals.erase(intervals.find(x - a));
        intervals.insert(b - a);
      }
    }
    if (*it2 != 0 && *it2 != n.size()) {
      if (it2 == split.end()) {
        split.insert(x - 1);
        it2 = split.find(x - 1);
        int a = *prev(it2);
        int b = *next(it2);
        intervals.erase(intervals.find(b - a));
        intervals.insert(b - x + 1);
        intervals.insert(x - a - 1);
      }
      else {
        it2 = split.find(x - 1);
        int a = *prev(it2);
        int b = *next(it2);
        split.erase(it2);
        intervals.erase(intervals.find(b - x + 1));
        intervals.erase(intervals.find(x - a - 1));
        intervals.insert(b - a);
      }
    }
    auto ans_it = intervals.end();
    --ans_it;
    cout << *ans_it << ' ';
  }
} 