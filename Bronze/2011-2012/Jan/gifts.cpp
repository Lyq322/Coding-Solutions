#include <iostream>
#include <algorithm>

using namespace std;

struct Gift {
  int price;
  int shipping;
};

int N, B;
int ans = 0;
Gift* gifts;
int* cost;

int check() {
  int total = 0;
  for (int i = 0; i < N; i++) {
    total = total + cost[i];
    if (total > B) {
      return i;
    }
  }
  return N;
}

int main() {
  cin >> N >> B;
  gifts = new Gift[N];
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    gifts[i].price = a;
    gifts[i].shipping = b;
  }
  cost = new int[N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == i) {
        cost[j] = gifts[j].price / 2 + gifts[j].shipping;
      }
      else {
        cost[j] = gifts[j].price + gifts[j].shipping;
      }
    }
    sort(cost, cost + N);
    ans = max(ans, check());
  }
  cout << ans << endl;
}