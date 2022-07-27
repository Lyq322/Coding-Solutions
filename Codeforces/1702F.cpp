#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		multiset<int> a;
		multiset<int> b;
		int c;
		for (int i = 0; i < N; i++) {
			cin >> c;
			while (c % 2 == 0) c /= 2;
			a.insert(c);
		}
		for (int i = 0; i < N; i++) {
			cin >> c;
			b.insert(c);
		}
		bool br = false;
		for (auto it = b.begin(); it != b.end(); ++it) {
			int num = *it;
			while (a.find(num) == a.end()) {
				if (num == num / 2) break;
				num /= 2;
			}
			if (a.find(num) != a.end()) {
				a.erase(a.find(num));
			}
			else {
				cout << "NO" << endl;
				br = true;
				break;
			}
		}
		if (br) continue;
		cout << "YES" << endl;
	}
}
