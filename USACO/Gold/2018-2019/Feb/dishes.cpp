#include <bits/stdc++.h>
using namespace std;

vector<stack<int>> clean;
set<pair<int, int>> bot_stack;
stack<int> dry;

void elsie(int num) {
	for (int i = 0; i < clean.size(); i++) {
		while (!clean[i].empty()) {
			if (clean[i].top() < num) {
				dry.push(clean[i].top());
				clean[i].pop();
			}
			else {
				return;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	int dishes[100000];
	for (int i = 0; i < N; i++) {
		cin >> dishes[i];
	}
	bool found = false;
	for (int i = 0; i < N; i++) {
		if (dry.size() != 0 && dishes[i] < dry.top()) {
			cout << i << endl;
			found = true;
			break;
		}
		if (clean.size() == 0) {
			stack<int> s;
			s.push(dishes[i]);
			clean.push_back(s);
			bot_stack.insert({dishes[i], 0});
		}
		else {
			auto it = bot_stack.lower_bound({dishes[i], 0});
			if (it == bot_stack.end()) {
				stack<int> s;
				s.push(dishes[i]);
				clean.push_back(s);
				bot_stack.insert({dishes[i], clean.size() - 1});
			}
			else {
				int index = it -> second;
				if (clean[index].top() < dishes[i]) {
					elsie(dishes[i]);
					clean[index].push(dishes[i]);
				}
				else {
					clean[index].push(dishes[i]);
				}
			}
		}
	}
	if (!found) cout << N << endl;
}

/*
Notice that we cannot put dish i on top of dish j if i > j
We also cannot have dish i on a column to the right of dish j if i < j
This means that dish i must be put on the stack with bottom dish a_k such that a_k-1 < i < a_k AND the stack must be increasing from top to bottom 
	a_k can be found using lower_bound on a set with all bottom dish numbers
We will maintain 3 main variables
	Vector of stacks that represent the cleaned pile
	Set of pairs that contains the bottom dish number of all stacks in clean
	Stack that represent the cleaned pile
If the current dish cannot be put on a stack because the stack wouldn’t be in increasing order from top to bottom
	Need to dry
Answer is found when the current dish is smaller than the top of the dried stack
*/