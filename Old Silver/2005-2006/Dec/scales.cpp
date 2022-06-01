#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;

ll N, C;
vector<ll> carrots;
ll maximum = 0;
vector<ll> first_half;
vector<ll> second_half;

void generate1(string counter) {
  if (counter.size() == N / 2) {
    ll total = 0;
    for (int i = 0; i < counter.size(); i++) {
      if (counter.at(i) == '1') total += carrots[i];
    }
    first_half.push_back(total);
    return;
  }
  generate1(counter + '1');
  generate1(counter + '0');
}

void generate2(string counter) {
  if (counter.size() == N - N / 2) {
    ll total = 0;
    for (int i = 0; i < counter.size(); i++) {
      if (counter.at(i) == '1') total += carrots[N / 2 + i];
    }
    second_half.push_back(total);
    return;
  }
  generate2(counter + '1');
  generate2(counter + '0');
}

int main() {
  cin >> N >> C;
  ll a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    carrots.push_back(a);
  }
  generate1("");
  generate2("");
  sort(first_half.begin(), first_half.end());
  sort(second_half.begin(), second_half.end());
  cout << "HI " << endl;
  for (int i = 0; i < first_half.size(); i++) {
    cout << first_half[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < second_half.size(); i++) {
    cout << second_half[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < first_half.size(); i++) {
    cout << first_half[i] << ' ' << *prev(upper_bound(second_half.begin(), second_half.end(), C - first_half[i])) << endl;
    maximum = max(maximum, *prev(upper_bound(second_half.begin(), second_half.end(), C - first_half[i])) + first_half[i]);
  }
  cout << maximum << endl;
}