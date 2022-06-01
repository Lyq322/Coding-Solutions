#include <iostream>
#include <set>
#include <vector>

using namespace std;

int K;
int A, B;
vector<pair<int, int>> numA;
vector<pair<int, int>> numB;

int main() {
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> A >> B;
    for (int j = 10; j <= 15000; j++) {
      int NA = (A / 100) * j * j + ((A / 10) % 10) * j + ((A % 100) % 10);
      int NB = (B / 100) * j * j + ((B / 10) % 10) * j + ((B % 100) % 10);
      numA.push_back({NA, j});
      numB.push_back({NB, j});
    }
    int index1 = 0;
    int index2 = 0;
    while (index1 != numA.size() || index2 != numB.size()) {
      if (numA[index1].first == numB[index2].first) {
        cout << numA[index1].second << ' ' << numB[index2].second << endl;
        break;
      }
      else if (numA[index1].first < numB[index2].first) {
        index1++;
      }
      else {
        index2++;
      }
    }
  }
}