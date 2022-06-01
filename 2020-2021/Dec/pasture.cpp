#include <iostream>

using namespace std;

int N;
pair<int, int> cows[2500];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cows[i].first >> cows[i].second;
  }
  
}