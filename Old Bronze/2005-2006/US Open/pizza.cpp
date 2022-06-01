#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin;
ofstream fout;

int t, n;
vector<vector<int>> constraints;
int ans = 0;

void search(string topping) {
  if (topping.length() == t) {
    bool check = true;
    for (int i = 0; i < n; i++) {
      bool b = false;
      for (int j = 0; j < constraints[i].size(); j++) {
        if (topping[constraints[i][j] - 1] == '0') {
          b = true;
          break;
        }
      }
      if (!b) {
        check = false;
        break;
      }
    }
    if (check) {
      ans++;
    }
    return;
  }
  search(topping + '0');
  search(topping + '1'); 
}

int main() {
  fin.open("pizza.in");
  fout.open("pizza.out");
  fin >> t >> n;
  for (int i = 0; i < n; i++) {
    constraints.push_back({});
  }
  int z;
  for (int i = 0; i < n; i++) {
    fin >> z;
    int a;
    for (int j = 0; j < z; j++) {
      fin >> a;
      constraints[i].push_back(a);
    }
  }
  search("");
  cout << ans << endl;
}