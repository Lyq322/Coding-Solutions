#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
pii particles[100000];

bool comp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> particles[i].first >> particles[i].second;
  }
  sort(particles, particles + n, comp);
  int minimum[100000];
  int maximum[100000];
  minimum[0] = particles[0].second;
  maximum[n - 1] = particles[n - 1].second;
  for (int i = 1; i < n; i++) {
    minimum[i] = min(minimum[i - 1], particles[i].second); 
  }
  for (int i = n - 2; i > -1; i--) {
    maximum[i] = max(maximum[i + 1], particles[i].second);
  }
  cout << "minimum ";
  for (int i = 0; i < n; i++) {
    cout << minimum[i] << ' ';
  }
  cout << endl;
  cout << "maximum ";
  for (int i = 0; i < n; i++) {
    cout << maximum[i] << ' ';
  }
  cout << endl;
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (maximum[i + 1] < minimum[i]) {
      cout << i << endl;
      ans++;
    }
  }
  cout << ans << endl;
} 