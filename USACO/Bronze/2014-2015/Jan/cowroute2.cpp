#include <bits/stdc++.h>
using namespace std;

int A, B, N;
vector<vector<int>> cows;
int costs[500];
map<int, int> toA;
map<int, int> toB;

int main() {
	cin >> A >> B >> N;
	int cost, planes;
	for (int i = 0; i < N; i++) {
		cin >> cost >> planes;
		costs[i] = cost;
		cows.push_back({});
		int a;
		for (int j = 0; j < planes; j++) {
			cin >> a;
			cows[i].push_back(a);
		}
	}
	int ans = 2002;
	for (int i = 0; i < N; i++) {
		bool s = false;
		for (int j = 0; j < cows[i].size(); j++) {
			if (s) {
				if (cows[i][j] == B) {
					ans = min(ans, costs[i]);
					continue;
				}
				if (toA.find(cows[i][j]) == toA.end()) {
					toA[cows[i][j]] = costs[i];
				}
				else {
					toA[cows[i][j]] = min(toA[cows[i][j]], costs[i]);
				}
			}
			else if (cows[i][j] == A) {
				s = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		bool e = false;
		for (int j = cows[i].size() - 1; j > -1; j--) {
			if (e) {
				if (cows[i][j] == A) {
					ans = min(ans, costs[i]);
					continue;
				}
				if (toB.find(cows[i][j]) == toB.end()) {
					toB[cows[i][j]] = costs[i];
				}
				else {
					toB[cows[i][j]] = min(toB[cows[i][j]], costs[i]);
				}
			}
			else if (cows[i][j] == B) {
				e = true;
			}
		}
	}
	for (auto it = toA.begin(); it != toA.end(); it++) {
		int middle = it -> first;
		if (toB.find(middle) != toB.end()) {
			int c = it -> second + toB.find(middle) -> second;
			ans = min(ans, c);
		}
	}
    if (ans == 2002) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}
