#include <iostream>

using namespace std;

string s;


int main() {
  cin >> s;
  int d = 0;
  int a, b;
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) == '(') {
      d++;
      a++;
    }
    else {
      d--;
      b++;
    }
    if (d == -1) { 
      ans = b;
      break;
    }
    if (d <= 1) {
      a = 0;
    }
  }
  if (d > 0) {
    cout << a << endl;
  }
  else {
    cout << ans << endl;
  }
}

/*#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;
    int ans = 0;
    int d = 0;
    int a = 0;
    int b = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            d++;
            a++;
        }
        else {
            d--;
            b++;
        }
        
        if (d <= 1) {
            a = 0;
        }
        if (d == -1) {
            ans = b;
            break;
        }
    }
    
    if(d > 0)
        ans = a;
    
    cout << ans << "\n";
}*/