#include <bits/stdc++.h>
using namespace std;

// Define dp[i] as the lexicographically smallest string with size i that satisfies the conditions of the phrase

string phrase;

bool check(int index, string s) {
	for (int i = index; i < s.size() + index; i++) {
		if (phrase.at(i) != '?' && phrase.at(i) != s.at(i - index)) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	cin >> phrase;
	string words[1000];
	for (int i = 0; i < M; i++) {
		cin >> words[i];
	}
	sort(words, words + M);
	string dp[1001];
	for (int i = 0; i <= N; i++) {
		string s = "";
		for (int j = 0; j < i; j++) {
			s += "z";
		}
		dp[i] = s;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - words[j].size() >= 0 && dp[i] > dp[i - words[j].size()] + words[j] && check(i - words[j].size(), words[j]) && (dp[i - words[j].size()] + words[j]).size() == i) {
				dp[i] = dp[i - words[j].size()] + words[j];
			}
		}
	}
	cout << dp[N] << endl;
}
