#include <bits/stdc++.h>

using namespace std;

string s, t;
int Q;
bool possible[18][18];
char characters[18] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};

bool check(char a, char b) {
	string new_s = "";
	string new_t = "";
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == a || s.at(i) == b) {
			new_s += s.at(i);
		}
	}
	for (int i = 0; i < t.size(); i++) {
		if (t.at(i) == a || t.at(i) == b) {
			new_t += t.at(i);
		}
	}
	return new_s == new_t;
}

int main() {
	cin >> s;
	cin >> t;
	for (int i = 0; i < 18; i++) {
		for (int j = i; j < 18; j++) {
			possible[i][j] = check(characters[i], characters[j]);
			possible[j][i] = possible[i][j];
		}
	}

	cin >> Q;
	string q;
	for (int i = 0; i < Q; i++) {
		cin >> q;
		bool ans = true;
		for (int j = 0; j < q.size(); j++) {
			for (int k = j; k < q.size(); k++) {
				int first_char = q.at(j) - 'a';
				int second_char = q.at(k) - 'a';
				if (!possible[first_char][second_char]) {
					ans = false;
					break;
				}
			}
		}
		if (ans) {
			cout << "Y";
		}
		else {
			cout << "N";
		}
	}
	cout << endl;
}
