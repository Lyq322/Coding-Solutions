#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

ifstream fin;
ofstream fout;

int n;
pii particles[100000];
int maximum[100000];
int minimum[100000];

bool comp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  fin.open("moop.in");
  fout.open("moop.out");
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> particles[i].first >> particles[i].second;
  }
  sort(particles, particles + n, comp);
  minimum[0] = particles[0].second;
  for (int i = 1; i < n; i++) {
    minimum[i] = min(minimum[i - 1], particles[i].second);
  }
  maximum[n - 1] = particles[n - 1].second;
  for (int i = n - 2; i > -1; i--) {
    maximum[i] = max(maximum[i + 1], particles[i].second);
  }
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (minimum[i] > maximum[i + 1]) {
      ans++;
    }
  }
  fout << ans << endl;
} 