#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int n;
int numbers[8] = {14, 1, 2, 4, 7, 8, 11, 13};

int main() {
  fin.open("moobuzz.in");
  fout.open("moobuzz.out");
  fin >> n;
  int a = n % 8;
  int b = n / 8;
  if (a == 0) {
    b--;
  }
  int ans = 15 * b + numbers[a];
  fout << ans << endl;
}