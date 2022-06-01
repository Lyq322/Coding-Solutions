#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, p;
queue<int> cards;
vector<int> me;

int main() {
  cin >> n >> k >> p;
  for (int i = 1; i <= k; i++) {
    cards.push(i);
  }
  int cow = 1;
  for (int i = 0; i < k; i++) {
    cout << endl;
    cout << "cow " << cow << endl;
    int card = cards.front();
    cout << "card " << card << endl;
    cards.pop();
    if (cow == n) {
      me.push_back(card);
      cow = 1;
    }
    else {
      cow++;
    }
    for (int j = 0; j < p; j++) {
      card = cards.front();
      cards.pop();
      cards.push(card);
    }
  }
  sort(me.begin(), me.end());
  for (int i = 0; i < me.size(); i++) {
    cout << me[i] << endl;
  }
} 