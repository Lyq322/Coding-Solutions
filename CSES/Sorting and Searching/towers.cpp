#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
int n;
vector<set<int>> towers;
vector<int> top;
 
int main() {
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    int index = upper_bound(top.begin(), top.end(), a) - top.begin();
    if (index == top.size()) {
      top.push_back(a);
      set<int> new_set;
      new_set.insert(a);
      towers.push_back(new_set);
    }
    else {
      if (top[index] == a) {
        index++;
        if (index == top.size()) {
          top.push_back(a);
          set<int> new_set;
          new_set.insert(a);
          towers.push_back(new_set);
        }
      }
      else { 
        towers[index].insert(a);
        top[index] = *towers[index].begin();
      }
    }
  }
  cout << towers.size() << endl;
} 