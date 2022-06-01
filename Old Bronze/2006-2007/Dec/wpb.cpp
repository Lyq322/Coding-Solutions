#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

ifstream fin;
ofstream fout;

ll d;
string n;

bool prime(ll num) {
  for (ll i = 2; i <= (ll) sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  fin.open("prime.in");
  fout.open("prime.out");
  fin >> d >> n;
  if (2 * d > n.length()) {
    ll num = (ll) pow(10, d - 1);
    while (!prime(num)) {
      num++;
    }
    cout << num << num << endl;
  }
  else {
    ll minimum = -1;
    for (ll i = d; i <= n.length() - d; i++) {
      cout << "i " << i << endl;
      ll num1 = stoi(n.substr(0, i));
      ll num2 = stoi(n.substr(i, n.length() - i));
      bool added = false;
      while (!prime(num1)) {
        added = true;
        num1++;
      }
      if (added) {
        num2 = (ll) pow(10, (n.length() - i - 1));
      }
      cout << num1 << ' ' << num2 << endl;
      while (!prime(num2)) {
        num2++;
      }
      cout << num1 << ' ' << num2 << endl;
      ll final_num = stoi(to_string(num1) + to_string(num2));
      cout << num1 << ' ' << num2 << endl;
      if (minimum == -1 || minimum > final_num) {
        minimum = final_num;
      }
    }
    cout << minimum << endl;
  }
}