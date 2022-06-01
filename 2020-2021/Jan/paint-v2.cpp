#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, Q;
	string s;
	cin >> N >> Q;
	cin >> s;
	int forward[100001] = {0};
	int backward[100001] = {0};
	int last[26];
	for (int i = 0; i < 26; i++) {
		last[i] = -1;
	}
	int t = 0;
	for (int i = 0; i < N; i++) {
		int num = s.at(i) - 'A';
		if (last[num] == -1) {
			t++;
		}
		last[num] = i;
		forward[i + 1] = t;
		for (int j = num + 1; j < 26; j++) {
			last[j] = -1;
		}
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < 26; i++) {
		last[i] = -1;
	}
	t = 0;
	for (int i = 0; i < N; i++) {
		int num = s.at(i) - 'A';
		if (last[num] == -1) {
			t++;
		}
		last[num] = i;
		backward[N - i - 1] = t;
		for (int j = num + 1; j < 26; j++) {
			last[j] = -1;
		}
	}
	int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		cout << forward[a - 1] + backward[b] << endl;
	}
}
