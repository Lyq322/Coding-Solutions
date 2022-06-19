#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	int N;
	string s;
	for (int z = 0; z < T; z++) {
		cin >> N;
		cin.ignore();
		getline(cin, s);
		long long ans = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s.at(i - 1) == s.at(i)) {
				ans++;
			}
			else {
				ans += i + 1;
			}
		}
		cout << ans + 1 << endl;
	}
}
