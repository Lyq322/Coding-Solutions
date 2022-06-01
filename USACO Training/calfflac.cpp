#include <iostream>
#include <string>

using namespace std;

struct string_int {
  string s;
  int i;
};

string_int check_palindrome(string palindrome, int index, bool odd) {
  int a;
  int len = 0;
  string str = "";
  if (odd) {
    a = 1;
    str += palindrome.at(index);
  }
  else {
    a = 0;
  }
  int b = 1;
  while (true) {
    if (index - a < 0 || index + b >= palindrome.length()) {
      break;
    }
    if (!isalpha(palindrome.at(index - a))) {
      string d(1, palindrome.at(index - a));
      str.insert(0, d);
      a++;
    }
    else if (!isalpha(palindrome.at(index + b))) {
      str += palindrome.at(index + b);
      b++;
    }
    else {
      if (tolower(palindrome.at(index - a)) != tolower(palindrome.at(index + b))) {
        break;
      }
      str += palindrome.at(index + b);
      string d(1, palindrome.at(index - a));
      str.insert(0, d);
      a++;
      b++;
      len++;
    }
  }
  string_int ans;
  ans.s = str;
  ans.i = len;
  return ans;
}

string punctuation(string palindrome) {
  int a = 0;
  int b = 0;
  for (int i = 0; i < palindrome.length(); i++) {
    if (isalpha(palindrome.at(i))) {
      a = i;
      break;
    }
  }
  for (int j = palindrome.length() - 1; j > -1; j--) {
    if (isalpha(palindrome.at(j))) {
      b = j;
      break;
    }
  }
  if (a == b) {
    return palindrome;
  }
  return palindrome.substr(a, b - a + 1);
}
int main() {
  string t = "";
  string s = "";
  int ans = 0;
  while (!cin.eof()) {
    getline(cin,t);
    s = s + t + '\n';
  } 
  int a, b, l, m;
  string str1, str2;
  string str_ans;
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s.at(i))) {
      string_int c1 = check_palindrome(s, i, true);
      str1 = punctuation(c1.s);
      a = c1.i;
      l = 2 * a + 1;
      string_int c2 = check_palindrome(s, i, false);
      str2 = punctuation(c2.s);
      b = c2.i;
      m = 2 * b;
      if (ans < l) {
        ans = l;
        str_ans = str1;
      }
      if (ans < m) {
        ans = m;
        str_ans = str2;
      }
    }
  }
  cout << ans << '\n';
  cout << str_ans << '\n';
}