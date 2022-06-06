#include <bits/stdc++.h>
using namespace std;

int T;
string s;

bool check(int cost) {
	int i = 0;
	int j = 0;
	int t_ones = 0;
	int zeros = 0;
	int ones = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '1') {
			t_ones++;
		}
	}
	while (i < s.size()) {
		if (t_ones - ones > cost) {
			if (j < s.size()) {
				if (s.at(j) == '1') {
					ones++;
				}
				else {
					zeros++;
				}
			}
			if (j == s.size()) {
				break;
			}
			j++;
		}
		else if (zeros > cost) {
			if (i < s.size()) {
				if (s.at(i) == '1') {
					ones--;
				}
				else {
					zeros--;
				}
			}
			i++;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	cin >> T;
	cin.ignore();
	for (int z = 0; z < T; z++) {
		getline(cin, s);
		cout << s << endl;
		int l = 0;
		int h = s.size();
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
}

/*
Binary search works
	If cost k works, then cost k + 1 also works
To check if a cost works, we can use sliding window
	If too many zeros in the current window, move left pointer forward
	If too less ones in the current window, move right pointer forward
*/