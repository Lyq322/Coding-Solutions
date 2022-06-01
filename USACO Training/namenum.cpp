#include <iostream>

using namespace std;

string num;

int main() {
  cin >> num;
  string word;
  bool c = true;
  while (!cin.eof()) {
    cin >> word;
    if (word.size() != num.size()) {
      continue;
    }
    bool b = true;
    for (int i = 0; i < word.size(); i++) {
      if (word.at(i) == 'Q' || word.at(i) == 'Z' || num.at(i) == '1' || num.at(i) == '0') {
        b = false;
        break;
      }
      else if (word.at(i) == 'A' || word.at(i) == 'B' || word.at(i) == 'C'){
        if (num.at(i) != '2') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'D' || word.at(i) == 'E' || word.at(i) == 'F'){
        if (num.at(i) != '3') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'G' || word.at(i) == 'H' || word.at(i) == 'I'){
        if (num.at(i) != '4') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'J' || word.at(i) == 'K' || word.at(i) == 'L'){
        if (num.at(i) != '5') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'M' || word.at(i) == 'N' || word.at(i) == 'O'){
        if (num.at(i) != '6') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'P' || word.at(i) == 'R' || word.at(i) == 'S'){
        if (num.at(i) != '7') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'T' || word.at(i) == 'U' || word.at(i) == 'V'){
        if (num.at(i) != '8') {
          b = false;
          break;
        }
      }
      else if (word.at(i) == 'W' || word.at(i) == 'X' || word.at(i) == 'Y'){
        if (num.at(i) != '9') {
          b = false;
          break;
        }
      }
    }
    if (b) {
      c = false;
      cout << word << endl;
    }
  }
  if (c) {
    cout << "NONE\n";
  }
}