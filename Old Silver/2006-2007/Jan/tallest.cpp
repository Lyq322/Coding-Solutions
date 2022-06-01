#include <bits/stdc++.h>
using namespace std;

int N, I, H, R;
int trees[10000] = {0};
set<pair<int, int>> s;
int ps[10001];

int main() {
	cin >> N >> I >> H >> R;
	int a, b;
	for (int i = 0; i < R; i++) {
		cin >> a >> b;
		if (s.find({a, b}) != s.end()) {
			continue;
		}
		s.insert({a, b});
		if (a < b) {
			trees[a] -= 1;
			trees[b - 1] += 1;
		}
		else if (a > b) {
			trees[b] -= 1;
			trees[a - 1] += 1;
		}
	}
	ps[0] = 0;
	for (int i = 0; i < N; i++) {
		ps[i + 1] = ps[i] + trees[i];
	}
	for (int i = 1; i < N + 1; i++) {
		cout << H + ps[i] << endl;
	}
}

/*
Solution
	Interval problem (?)
	a can see b -> arr[a] -= 1, arr[b - 1] += 1
	Prefix sum
	O(N)
Key Observations
	If we have a can see b, then every tree between a and b, exclusive, has to be shorter than the minimum of a and b
	It doesn’t matter how much shorter
	We want to find the maximum height of each tree, so we let every tree between a and b, exclusive, be 1 unit shorter
	This turns the problem into an interval problem that can be solved using prefix sum
*/
