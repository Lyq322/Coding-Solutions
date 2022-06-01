#include <iostream>
#include <fstream>

using namespace std;

int a, b, n;

ifstream fin;
ofstream fout;

int main() {
  fin.open("route.in");
  fout.open("route.out");
  fin >> a >> b >> n;
  int cost, l;
  int minimum = -1;
  cout << a << ' ' << b << endl;
  for (int i = 0; i < n; i++) {
    fin >> cost >> l;
    int stop;
    int s = 0;
    int f = 0;
    cout << "cost " << cost << endl;
    for (int j = 0; j < l; j++) {
      fin >> stop;
      if (stop == a) {
        s = j;
      }
      if (stop == b) {
        f = j;
      }
    }
    if (s != -1 && f != -1 && s < f && (minimum == -1 || cost < minimum)) {
      minimum = cost;
    }
  }
  fout << minimum << endl;
}