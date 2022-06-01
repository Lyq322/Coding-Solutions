#include <bits/stdc++.h>
using namespace std;

int N, G;
vector<set<int>> cows;

int main() {
	cin >> N >> G;
	for (int i = 0; i < N; i++) {
		cows.push_back({});
	}
	int a;
	for (int i = 0; i < G; i++) {
		cin >> a;
		int b;
		for (int j = 0; j < a; j++) {
			cin >> b;
			cows[i].insert(b);
		}
	}
	vector<int> current;
	current.push_back(1);
	for (int j = 0; j < G; j++) {
		if (cows[j].find(1) != cows[j].end()) cows[j].erase(1);
	}
	while (true) {
		bool cont = false;
		for (int i = 0; i < G; i++) {
			if (cows[i].size() == 1) {
				cont = true;
				int next = *cows[i].begin();
				current.push_back(next);
				cows[i].clear();
				for (int j = 0; j < G; j++) {
					if (i == j) continue;
					if (cows[j].find(next) != cows[j].end()) cows[j].erase(next);
				}
			}
		}
		if (!cont) break;
	}
	cout << current.size() << endl;
}

/*
Pseudocode
	Put each group in a sorted set
	Vector for current members, put 1 in there initially
	While loop
		Loop through vector of sets
		Find sets with size of 1 -> have to include in the party -> add the only element in set to current members vector
	If no set with size of 1 -> break
*/