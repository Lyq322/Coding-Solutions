#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	int a, b;
	ll square1, square2;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		square1 = (ll) (max(a, b) - 1) * (max(a, b) - 1);
		square2 = (ll) max(a, b) * max(a, b);
		if (a == b) {
			cout << square1 + a << endl;
		}
		else if (max(a, b) % 2 == 0) {
			if (a < b) cout << square1 + a << endl;
			else cout << square2 - b + 1 << endl;
		}
		else {
			if (a < b) cout << square2 - a + 1 << endl;
			else cout << square1 + b << endl;
		}
	}
}
