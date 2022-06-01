#include <bits/stdc++.h>
using namespace std;

int N;
int cows[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}
	sort(cows, cows + N, greater<int> ());
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (v.size() <= cows[i]) {
			v.push_back(cows[i]);
		}
	}
	cout << v.size() << endl;
}
