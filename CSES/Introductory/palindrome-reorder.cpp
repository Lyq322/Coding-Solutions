#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int letters[26] = {0};
	for (int i = 0; i < s.size(); i++) {
		letters[s[i] - 'A']++;
	}
	int odd = 0;
	int index;
	for (int i = 0; i < 26; i++) {
		if (letters[i] % 2 == 1) {
			odd++;
			index = i;
		}
	}
	if (odd > 1) {
		cout << "NO SOLUTION" << endl;
	}
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < letters[i] / 2; j++) {
				cout << (char) ('A' + i);
			}
		}
		if (odd == 1) cout << (char) ('A' + index);
		for (int i = 25; i > -1; i--) {
			for (int j = 0; j < letters[i] / 2; j++) {
				cout << (char) ('A' + i);
			}
		}
		cout << endl;
	}
}
