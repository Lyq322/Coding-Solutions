#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

/*
We can find the answer by first finding the number of different rhyme patterns (the num of distinct chars from input)
For each distinct rhyme pattern, we want to loop through the number of words possible as the last word in that line. This means we would want to find the number of words with the same rhyme
Better explanation through the official example:
	There are two words that has a rhyme class of 1 (word 1 and 2), and one word that has a rhyme class of 2 (word 3)
	For rhyme class 1, there are 8 ways to create a line with a word that has rhyme class 1 at the end, and for rhyme class 2, there are 4 ways to create a line with a word that has rhyme class 2 at the end (these numbers can be calculated using a dp knapsack with repetition)
	In the poem, there are two lines with a rhyme class of A and one line with a rhyme class of B
	This means for rhyme class A, there are 8^2 + 4^2 ways (num^2 is because A occurs twice; if A appears three times, then it would be 8^3 + 4^3). For rhyme class B, there are 8^1 + 4^1 ways
	Since rhyme class can be the same for A and B, we know that the answer is (8^2+4^2)(8^1+4^1) = 960

Also, we need to use an exponential algorithm to speed up the algorithm so that it runs in time
*/

bool comp(pii a, pii b) {
	return a.second < b.second;
}

ll cal(ll num, ll times) {
	if (times == 0) return 1;
	if (times == 1) return num;
	ll ans = cal(num, times / 2);
	ans = (ans * ans) % 1000000007;
	if (times % 2 == 1) {
		ans = (ans * num) % 1000000007;
	}
	return ans % 1000000007;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<pii> words;
	int a, b;
	char rhyme[100000];
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (b <= K) {
			words.push_back({a, b});
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> rhyme[i];
	}
	// Knapsack with repetition
	int dp_ks[5001] = {0};
	dp_ks[0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < N; j++) {
			if (i - words[j].first >= 0) {
				dp_ks[i] = (dp_ks[i] + dp_ks[i - words[j].first]) % 1000000007;
			}
		}
	}
	ll rhyme_count[5001] = {0};
	for (int i = 0; i < N; i++) {
		rhyme_count[words[i].second] = (rhyme_count[words[i].second] + dp_ks[K - words[i].first]) % 1000000007;
	}
	int count_rhyme[26] = {0};
	for (int i = 0; i < M; i++) {
		count_rhyme[rhyme[i] - 'A']++;
	}
	ll ans = 1;
	for (int i = 0; i < 26; i++) {
		if (count_rhyme[i] == 0) continue;
		ll c = 0;
		for (int k = 0; k <= N; k++) {
			if (rhyme_count[k] == 0) continue;
			c = (c + cal(rhyme_count[k], count_rhyme[i])) % 1000000007;
		}
		ans = (ans * c) % 1000000007;
	}
	cout << ans << endl;
}
