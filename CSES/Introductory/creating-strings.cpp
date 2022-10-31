#include <bits/stdc++.h>
using namespace std;

set<string> st;

void solve(string a, int pos) {
	if (pos == a.size()) {
		st.insert(a);
	}
	for (int i = pos; i < a.size(); i++) {
		if (a[pos] == a[i] && pos != i) continue;
		char temp = a[pos];
		a[pos] = a[i];
		a[i] = temp;
		solve(a, pos + 1);
		temp = a[pos];
		a[pos] = a[i];
		a[i] = temp;
	}
}

int main() {
	string s;
	cin >> s;
	solve(s, 0);
	cout << st.size() << endl;
	for (string p : st) {
		cout << p << endl;
	}
}
