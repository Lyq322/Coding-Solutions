#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, X, Y, Z;
vector<int> dirt1;
vector<int> dirt2;
int dp[1001][1001];

int solve(int a, int b){
	if (dp[a][b] != -1) return dp[a][b];
	if (dirt1[a - 1] == dirt2[b - 1]) {
		dp[a][b] = solve(a - 1, b - 1);
	}
	else {
		dp[a][b] = solve(a - 1, b) + Y;
		dp[a][b] = min(dp[a][b], solve(a, b - 1) + X);
		dp[a][b] = min(dp[a][b], solve(a - 1, b - 1) + abs(dirt1[a - 1] - dirt2[b - 1]) * Z);
	}
	return dp[a][b];
}

int main() {
	cin >> N >> X >> Y >> Z;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			dirt1.push_back(i + 1);
		}
		for (int j = 0; j < b; j++) {
			dirt2.push_back(i + 1);
		}
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < dirt1.size(); i++) {
		dp[i + 1][0] = (i + 1) * Y;
	}
	for (int i = 0; i < dirt2.size(); i++) {
		dp[0][i + 1] = (i + 1) * X;
	}
	solve(dirt1.size(), dirt2.size());
	cout << dp[dirt1.size()][dirt2.size()] << endl;
}

/*
No idea how people thought of this solution ?????
	Maybe because the input is small????
Change input into a different format
	For a flowerbed i with j amounts of dirt, the new arr will contain j i’s
	Eg. flowerbed 3 that has 2 amounts of dirt => push back 3 3
	String edit dp
*/