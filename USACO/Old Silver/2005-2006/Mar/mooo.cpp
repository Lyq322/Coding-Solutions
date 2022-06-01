#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
vector<pair<int, pii>> cows;
int ans[50000] = {0};
int left_arr[50000] = {0};
int right_arr[50000] = {0};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		left_arr[i] = -1;
		right_arr[i] = -1;
	}
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cows.push_back({a, {b, i}});
		if (i != 0 && i != N - 1) {
			left_arr[i] = i - 1;
			right_arr[i] = i + 1;
		}
		else if (i == 0) {
			right_arr[i] = 1;
		}
		else {
			left_arr[i] = i - 1;
		}
	}
	sort(cows.begin(), cows.end());
	for (int i = 0; i < N; i++) {
		int pos = cows[i].second.second;
		int water = cows[i].second.first;
		if (left_arr[pos] >= 0 && left_arr[pos] < N) {
			ans[left_arr[pos]] += water;
			right_arr[left_arr[pos]] = right_arr[pos];	
		}
		if (right_arr[pos] >= 0 && right_arr[pos] < N) {
			ans[right_arr[pos]] += water;
			left_arr[right_arr[pos]] = left_arr[pos];
		}
		left_arr[pos] = -1;
		right_arr[pos] = -1;
	}
	int maximum = 0;
	for (int i = 0; i < N; i++) {
		maximum = max(maximum, ans[i]);
	}
	cout << maximum << endl;
}

/*
Solution 1 - Strictly increasing/decreasing stack, 05/03
  Implementation
    Maintain a strictly increasing stack of pair<height, water>
    Iterate over the array using the stack twice, one forwards and once reverse
  O(N)
Solution 2 - Linked List (ish), 05/10
  Key Observations
    Cows left and right of the shortest cow in the line will always hear them
  Pseudocode
    Sort by height
    Create left and right arr, storing the index of the cow to the left of i and to the right of i (initially, left[i] = i - 1 and right[i] = i + 1 except when i = 0, N-1)
  O(N)
*/