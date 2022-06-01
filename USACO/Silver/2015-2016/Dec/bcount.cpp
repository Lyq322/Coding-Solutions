#include <iostream>

using namespace std;

int n, q;
int cows[100000];
pair<int, int> queries[100000];
int pf1[100001];
int pf2[100001];
int pf3[100001];

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> cows[i];
  }
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    queries[i].first = a;
    queries[i].second = b;
  }
  int total1 = 0, total2 = 0, total3 = 0;
  pf1[0] = 0;
  pf2[0] = 0;
  pf3[0] = 0;
  for (int i = 0; i < n; i++) {
    if (cows[i] == 1) {
      total1++;
    }
    else if (cows[i] == 2) {
      total2++;
    }
    else {
      total3++;
    }
    pf1[i + 1] = total1;
    pf2[i + 1] = total2;
    pf3[i + 1] = total3;
  }
  for (int i = 0; i < q; i++) {
    cout << pf1[queries[i].second] - pf1[queries[i].first - 1] << ' ';
    cout << pf2[queries[i].second] - pf2[queries[i].first - 1] << ' ';
    cout << pf3[queries[i].second] - pf3[queries[i].first - 1] << endl;
  }
}