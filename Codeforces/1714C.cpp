#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v;
		for (int i = 9; i > 0; i--) {
			if (N >= i) {
				N -= i;
				v.push_back(i);
			}
		}
		for (int i = v.size() - 1; i > -1; i--) {
			cout << v[i];
		}
		cout << endl;
	}
}
