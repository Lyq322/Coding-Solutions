#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Cow {
  long long int w;
  long long int u;
};

int N, M;
int a, b, c, d, e, f, g, h;
Cow cow[1500000];

bool comp(Cow a, Cow b) {
  if (a.u == b.u) {
    return a.w < b.w;
  }
  return a.u > b.u;
} 

int main() {
  cin >> N >> a >> b >> c >> d >> e >> f >> g >> h >> M;
  long long int r;
  long long int n1, n2;
  for (int i = 0; i < 3 * N; i++) {
    //cout << "i " << i << endl;
    r = 1;
    for (int j = 0; j < 5; j++) {
      r = r * (i % d);
      r = r % d;
    }
    n1 = ((a % d) * r) % d;
    r = 1;
    for (int j = 0; j < 2; j++) {
      r = r * (i % d);
      r = r % d;
    }
    n2 = ((b % d) * r) % d;
    cow[i].w = (n1 + n2 + c % d) % d;
    n1 = e % h;
    for (int j = 0; j < 5; j++) {
      n1 = n1 * (i % h);
      n1 = n1 % h;
    }
    n2 = f % h;
    for (int j = 0; j < 3; j++) {
      n2 = n2 * (i % h);
      n2 = n2 % h;
    }
    cow[i].u = n1;
    cow[i].u = (cow[i].u + n2 % h) % h;
    cow[i].u = (cow[i].u + g) % h;
    //cout << cow[i].w << ' ' << cow[i].u << endl;
  }
  sort(cow, cow + 3 * N, comp);
  long long int weight = 0;
  //for (int i = 0; i < N; i++) {
    //cout << cow[i].u << endl;
  //}
  for (int i = 0; i < N; i++) {
    weight = weight + cow[i].w;
    weight = weight % M;
  }
  cout << weight << endl;
}