#include <iostream>
#include <fstream>

using namespace std;

int N, M;
long int path_a[1000000];
long int path_b[1000000];
int ans = 0;

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("greetings.in");
  fout.open("greetings.out");
  fin >> N >> M;
  int d;
  char c;
  path_a[0] = 0;
  path_b[0] = 0;
  int index = 1;
  long long int abc = 0;
  for (int i = 0; i < N; i++) {
    fin >> d >> c;
    abc = abc + d;
    if (c == 'L') {
      for (int j = 0; j < d; j++) {
        path_a[index] = path_a[index - 1] - 1;
        index++;
      }
    }
    else {
      for (int j = 0; j < d; j++) {
        path_a[index] = path_a[index - 1] + 1;
        index++;
      }
    }
  }
  cout << abc << endl;
  int max_a = index;
  index = 1;
  for (int i = 0; i < M; i++) {
    fin >> d >> c;
    if (c == 'L') {
      for (int j = 0; j < d; j++) {
        path_b[index] = path_b[index - 1] - 1;
        index++;
      }
    }
    else {
      for (int j = 0; j < d; j++) {
        path_b[index] = path_b[index - 1] + 1;
        index++;
      }
    }
  }
  cout << "ans123 " << ans << endl;
  int max_b = index;
  if (max_a < max_b) {
    for (int i = max_a; i < max_b; i++) {
      path_a[i] = path_a[i-1];
    }
  }
  else if (max_b < max_a) {
    for (int i = max_b; i < max_a; i++) {
      path_b[i] = path_b[i-1];
    }
  }
  int mm = max(max_a, max_b);
  bool apart = false;
  for (int i = 0; i < mm; i++) {
    //cout << path_a[i] << ' ' << path_b[i] << endl;
    //cout << apart << endl;
    if (path_a[i] == path_b[i] && apart) {
      cout << "i " << i << endl;
      ans++;
      cout << "ans " << ans << endl;
      apart = false;
    }
    else if (path_a[i] != path_b[i] && !apart) {
      apart = true;
    }
  }
  fout << ans << endl;
}

/*#include <iostream>
#include <fstream>

using namespace std;

int N, M;
long long int path_a[1000000];
long long int path_b[1000000];
int ans = 0;

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("greetings.in");
  fout.open("greetings.out");
  fin >> N >> M;
  long int d;
  char c;
  long int index = 0;
  for (int i = 0; i < N; i++) {
    fin >> d >> c;
    if (c == 'L') {
      for (int j = 0; j < d; j++) {
        path_a[index] = path_a[index - 1] - 1;
        index++;
      }
    }
    else {
      for (int j = 0; j < d; j++) {
        path_a[index] = path_a[index - 1] + 1;
        index++;
      }
    }
  }
  long long int max_a = index;
  index = 1;
  for (int i = 0; i < M; i++) {
    fin >> d >> c;
    if (c == 'L') {
      for (int j = 0; j < d; j++) {
        path_b[index] = path_b[index - 1] - 1;
        index++;
      }
    }
    else {
      for (int j = 0; j < d; j++) {
        path_b[index] = path_b[index - 1] + 1;
        index++;
      }
    }
  }
  long long int max_b = index;
  if (max_a < max_b) {
    for (long int i = max_a; i < max_b; i++) {
      path_a[i] = path_a[i-1];
    }
  }
  else if (max_b < max_a) {
    for (long int i = max_b; i < max_a; i++) {
      path_b[i] = path_b[i-1];
    }
  }
  long long int mm = max(max_a, max_b);
  cout << mm << endl;
  bool apart = false;
  for (long long int i = 0; i < mm; i++) {
    //cout << path_a[i] << ' ' << path_b[i] << endl;
    //cout << apart << endl;
    if (path_a[i] == path_b[i] && apart) {
      //cout << "i " << i << endl;
      //cin.ignore();
      ans++;
      apart = false;
    }
    else if (path_a[i] != path_b[i] && !apart) {
      apart = true;
    }
  }
  fout << ans << endl;
}*/