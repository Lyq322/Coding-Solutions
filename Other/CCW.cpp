#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

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

int main() {
	cout << "Hello World!" << endl;
}
