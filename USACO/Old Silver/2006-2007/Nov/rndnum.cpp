#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[32][32];

int cal(int i, int cur_o, int cur_z) {
	int t = 0;
	for (int j = 0; j <= i; j++) {
		for (int k = 0; k <= i; k++) {
			if (j + k == i && j + k >= 1 && j + cur_z >= k + cur_o) {
				t += dp[j + k][j];
			}
		}
	}
	return t;
}

int main() {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < 32; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i < 32; i++) {
		for (int j = 1; j < 32; j++) {
			if (i - 1 >= j) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	int a, b;
	cin >> a >> b;
	a--;
	vector<int> v;
	int ones = 1;
	int zeros = 0;
	int v1 = 0;
	if (a != 0) {
		while (a > 0) {
			if (a % 2 == 1) {
				v.push_back(1);
			}
			else {
				v.push_back(0);
			}
			a = a >> 1;
		}
		reverse(v.begin(), v.end());
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == 1) {
				v1 += cal(v.size() - i - 1, ones, zeros + 1);
				ones++;
				if (i == v.size() - 1) {
					if (zeros + 1 >= ones - 1) v1++;
				}
			}
			else zeros++;
		}
		if (zeros >= ones) v1++;
		for (int i = 1; i < v.size() - 1; i++) {
			v1 += cal(i, 1, 0);
		}
	}
	else {
		v1 = 0;
	}
	v.clear();
	while (b > 0) {
		if (b % 2 == 1) {
			v.push_back(1);
		}
		else {
			v.push_back(0);
		}
		b = b >> 1;
	}
	reverse(v.begin(), v.end());
	ones = 1;
	zeros = 0;
	int v2 = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 1) {
			v2 += cal(v.size() - i - 1, ones, zeros + 1);
			ones++;
			if (i == v.size() - 1) {
				if (zeros + 1 >= ones - 1) v2++;
			}
		}
		else zeros++;
	}
	if (zeros >= ones) v2++;
	for (int i = 1; i < v.size() - 1; i++) {
		v2 += cal(i, 1, 0);
	}
	cout << v2 - v1 << endl;
}

/*
Combinatorics
Veeeerryyy bad implementation lol. It took sooo long to do this problem
We need a dp array to store (n choose k) since using factorials will be over the integer limit
*/