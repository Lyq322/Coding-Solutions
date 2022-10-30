#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if ((a + b) % 3 != 0) {
			cout << "NO" << endl;
		}
		else if (max(a, b) > 2 * min(a, b)) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}
