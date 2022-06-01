#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> cows;

int check(int c) {
	if (c >= N) {
		return true;
	}
	priority_queue<int> pq;
	for (int i = 0; i < c; i++) {
		pq.push(cows[i]);
	}
	int t;
	for (int i = c; i < N; i++) {
		t = pq.top();
		pq.pop();
		pq.push(cows[i] + t);
	}
	int minimum = 0;
	while (!pq.empty()) {
		minimum = min(minimum, pq.top());
		pq.pop();
	}
	int total_time = 0 - minimum;
	if (total_time <= T) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin >> N >> T;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		cows.push_back(0 - a);
	}
	int l = 0;
	int h = 10000;
	int m;
	while (l <= h) {
		m = l + (h - l) / 2;
		if (check(m) && (m == 0 || !check(m - 1))) {
			cout << m << endl;
			break;
		}
		else if (check(m)) {
			h = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}

/*
  Solution
    Binary Search on a function check() that checks whether the parameter K can satisfy the condition
    Find first true
    O(NlogN)
  Key Observations
    If K = a works, then K = a + 1, a + 2, … will always work. Similarly, if K = a does not work, then K = a - 1, a - 2, … will always not work. 
    Standard binary search question — we want to find the first occurrence of when check() function returns true
*/