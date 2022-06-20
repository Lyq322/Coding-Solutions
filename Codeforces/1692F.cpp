#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				if ((i + j + k) % 10 == 3) {
					v.push_back({{i, j}, k});
				}
			}
		}
	}
	for (int z = 0; z < T; z++) {
		int N;
		cin >> N;
		int a;
		int digit[10] = {0};
		for (int i = 0; i < N; i++) {
			cin >> a;
			digit[a % 10]++;
		}
		bool found = false;
		for (int i = 0; i < v.size(); i++) {
			digit[v[i].first.first]--;
			digit[v[i].first.second]--;
			digit[v[i].second]--;
			bool b = true;
			for (int j = 0; j < 10; j++) {
				if (digit[j] < 0) {
					b = false;
					break;
				}
			}
			if (b) {
				cout << "yes" << endl;
				found = true;
				break;
			}
			digit[v[i].first.first]++;
			digit[v[i].first.second]++;
			digit[v[i].second]++;
		}
		if (!found) {
			cout << "no" << endl;
		}
	}
}
