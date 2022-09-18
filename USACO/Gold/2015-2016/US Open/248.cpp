#include <bits/stdc++.h>
using namespace std;

/*
For the dp solution, let dp[i][j] be defined as the maximum score when using the interval from i through j, since if we are trying to merge from left to right and at index x doesn’t work, all indices less than x also won’t work
For the stack solution (this solution)
Loop through the possible indices where the numbers will merge into the final number (largest number)
ie. Loop through i such that the largest possible number is found when merging everything to the left of i to i and everything to the right of i + 1 to i + 1, and merging i and i + 1 at the end
If index i and i + 1 have different maximums, then choose the smallest one
To calculate the largest possible number when merging everything to the left of i to i (same for i + 1), we can run a stack to simulate merging
The answer could also be just the maximum of a single index
*/

int main() {
	int N;
	cin >> N;
	int arr[248] = {0};
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		ans = max(ans, arr[i]);
	}
	stack<int> s;
	for (int i = 0; i < N; i++) {
		s.push(arr[i]);
		while (s.size() >= 2) {
			int t = s.top();
			s.pop();
			if (s.top() == t) {
				s.pop();
				s.push(t + 1);
			}
			else {
				s.push(t);
				break;
			}
		}
	}
	while (s.size() != 1) {
		s.pop();
	}
	ans = max(ans, s.top());
	s.pop();
	for (int i = N - 1; i > -1; i--) {
		s.push(arr[i]);
		while (s.size() >= 2) {
			int t = s.top();
			s.pop();
			if (s.top() == t) {
				s.pop();
				s.push(t + 1);
			}
			else {
				s.push(t);
				break;
			}
		}
	}
	while (s.size() != 1) {
		s.pop();
	}
	ans = max(ans, s.top());
	s.pop();
	for (int i = 0; i < N - 1; i++) {
		int min1, max1, min2, max2;
		for (int j = i; j > -1; j--) {
			s.push(arr[j]);
			while (s.size() >= 2) {
				int t = s.top();
				s.pop();
				if (s.top() == t) {
					s.pop();
					s.push(t + 1);
				}
				else {
					s.push(t);
					break;
				}
			}
		}
		min1 = arr[i];
		while (s.size() != 1) {
			s.pop();
		}
		max1 = s.top();
		s.pop();
		for (int j = i + 1; j < N; j++) {
			s.push(arr[j]);
			while (s.size() >= 2) {
				int t = s.top();
				s.pop();
				if (s.top() == t) {
					s.pop();
					s.push(t + 1);
				}
				else {
					s.push(t);
					break;
				}
			}
		}
		min2 = arr[i + 1];
		while (s.size() != 1) {
			s.pop();
		}
		max2 = s.top();
		s.pop();

		if (max1 < min2 && max2 < min1) continue;
		ans = max(ans, min(max1, max2) + 1);
		ans = max(ans, max(max1, max2));
	}
	cout << ans << endl;
}
