#include <iostream>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    string num_bin;
    if (a.at(i) == '0') {
      num_bin = a.substr(0,i) + '1' + a.substr(i+1,a.length()-i+1);
    }
    else {
      num_bin = a.substr(0,i) + '0' + a.substr(i+1,a.length()-i+1);
    }
    //cout << "binary " << num_bin << endl;
    for (int j = 0; j < b.length(); j++) {
      string num_ter;
      if (b.at(j) == '0') {
        num_ter = b.substr(0,j) + '1' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
        num_ter = b.substr(0,j) + '2' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
      }
      else if (b.at(j) == '1') {
        num_ter = b.substr(0,j) + '0' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
        num_ter = b.substr(0,j) + '2' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
      }
      else {
        num_ter = b.substr(0,j) + '0' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
        num_ter = b.substr(0,j) + '1' + b.substr(j+1,b.length()-j+1);
        //cout << "ternary " << num_ter << endl;
        if (stoi(num_bin, nullptr, 2) == stoi(num_ter, nullptr, 3)) {
          cout << stoi(num_bin, nullptr, 2) << endl;
          break;
        }
      }
    }
  }
}