#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long int X, Y;
  cin >> X >> Y;
  long long int number;
  long long int n;
  int ans = 0;
  int digit;
  for (int i = 3; i <= 17; i++) { // size
    for (int j = 0; j < i; j++) { // pos
      for (int k = 0; k < 10; k++) { // different
        for (int l = 0; l < 10; l++) { // same
          number = 0;
          digit = i - 1;
          if (k != l) {
            if (k == 0) {
              if (j == 0) {
                continue;
              }
              for (int m = 0; m < j; m++) {
                n = ((long long int) pow(10.0, digit)) * l;
                number += n;
                digit--;
              }
              n = ((long long int) pow(10.0, digit)) * k;
              number += n;
              digit--;
              for (int m = 0; m < i - j - 1; m++) {
                n = ((long long int) pow(10.0, digit)) * l;
                number += n;
                digit--;
              }
            }
            else if (l == 0) {
              if (j != 0) {
                continue;
              }
              n = ((long long int) pow(10.0, digit)) * k;
              number += n;
              digit--;
              for (int m = 0; m < i - 1; m++) {
                n = ((long long int) pow(10.0, digit)) * l;
                number += n;
                digit--;
              }
            }
            else {
              for (int m = 0; m < j; m++) {
                n = ((long long int) pow(10.0, digit)) * l;
                number += n;
                digit--;
              }
              n = ((long long int) pow(10.0, digit)) * k;
              number += n;
              digit--;
              for (int m = 0; m < i - j - 1; m++) {
                n = ((long long int) pow(10.0, digit)) * l;
                number += n;
                digit--;
              }
            }
            if (X <= number && number <= Y) {
              cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
              cout << number << endl;
              ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}