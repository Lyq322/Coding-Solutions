#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int ccw(pii a, pii b, pii c) {
	ll area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (area > 0) {
		return 1;
	}
	else if (area < 0) {
		return -1;
	}
	else return 0;
}

bool check(pii p1, pii p2, pii q1, pii q2) { // Missing some cases
    int r1 = ccw(p1, p2, q1) * ccw(p1, p2, q2);
    int r2 = ccw(q1, q2, p1) * ccw(q1, q2, p2);
	return (r1 <= 0 && r2 <= 0);
}

int main() {
	cout << "Hello World!" << endl;
}
