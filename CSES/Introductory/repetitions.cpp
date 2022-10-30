#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int index = 0;
	int count = 1;
	int ans = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[index]) {
			count++;
		}
		else {
			ans = max(ans, count);
			count = 1;
			index = i;
		}
	}
	ans = max(ans, count);
	cout << ans << endl;
}
