#include <bits/stdc++.h>
using namespace std;

struct pii {
	int first;
	int second;
};

bool operator<(pii a, pii b) {
	return a.first > b.first;
}

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N, M;
		int arr[50];
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			arr[i]--;
		}
		priority_queue<pii> q;
		for (int i = 0; i < N; i++) {
			q.push({min(arr[i], M - arr[i] - 1), max(arr[i], M - arr[i] - 1)});
		}
		string s = "";
		for (int i = 0; i < M; i++) {
			s += 'B';
		}
		while (!q.empty()) {
			pii pos = q.top();
			q.pop();
			if (s.at(pos.first) == 'B') {
				s[pos.first] = 'A';
			}
			else {
				if (pos.second == -1) {
					continue;
				}
				else {
					q.push({pos.second, -1});
				}
			}
		}
		cout << s << endl;
	}
}
