#include <bits/stdc++.h>
using namespace std;

/*
For each number in the list, we can either get a response of Hi, Lo or nothing (if Elsie choose to not ask)
If we go through each x from 0 through N, the responses for a certain number in the list always go from None -> Hi -> Lo -> None
	For example, for 5 1 2 4 3 6, for 4 we have (for x from 0 thr 6) none, none, hi, hi, lo, none, none
	This guarantees that the total number of changes is only 3 * N
Elsie won’t ask about a certain number if there is a number k that has been asked before by Elsie and satisfies target < k < current. Similarly, if there is a number k that has been asked before and satisfies current < k < target, then Elsie also won’t ask about the current number
	This means that using a stack (keep track of strictly increasing sequences to count Lo’s, similarly for Hi’s), we can find the x where each number from the list changes states
Finally, we can use a map to keep track of the responses at each x, looping through the changes we found before and updating count of HiLo accordingly
*/

int main() {
	int N;
	cin >> N;
	int arr[200000];
	int index[200001];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		index[arr[i] - 1] = i;
	}
	vector<vector<pair<bool, int>>> insert;
	vector<vector<pair<bool, int>>> del;
	for (int i = 0; i <= N; i++) {
		insert.push_back({});
		del.push_back({});
	}
	// Find changes for Lo
	stack<int> s;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() > index[i]) {
			del[i + 1].push_back({true, s.top()});
			s.pop();
		}
		s.push(index[i]);
		insert[i + 1].push_back({true, index[i]});
	}
	while (!s.empty()) {
		del[N + 1].push_back({true, s.top()});
		s.pop();
	}
	// Find changes for Hi
	for (int i = N - 1; i > -1; i--) {
		while (!s.empty() && s.top() > index[i]) {
			insert[i + 1].push_back({false, s.top()});
			s.pop();
		}
		s.push(index[i]);
		del[i + 1].push_back({false, index[i]});
	}
	while (!s.empty()) {
		insert[0].push_back({false, s.top()});
		s.pop();
	}
	int count = 0;
	// map<index, Hi/Lo>
	// Hi = 0 = false
	// Lo = 1 = true
	map<int, int> hilo;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < del[i].size(); j++) {
			auto it = hilo.find(del[i][j].second);
			if (next(it) != hilo.end() && !del[i][j].first && next(it) -> second == 1) {
				count--;
			}
			else if (it != hilo.begin() && del[i][j].first && prev(it) -> second == 0) {
				count--;
			}
			hilo.erase(it);
		}
		for (int j = 0; j < insert[i].size(); j++) {
			auto it = hilo.find(insert[i][j].second);
			if (it != hilo.begin() && prev(it) -> second == 0 && insert[i][j].first) {
				count++;
			}
			else if (it != hilo.end() && it -> second == 1 && !insert[i][j].first) {
				count++;
			}
			hilo[insert[i][j].second] = (int) insert[i][j].first;
		}
		cout << count << endl;
	}
}
