#include <bits/stdc++.h>
using namespace std;

/*
Notice that whether K works or not depends on the subtree below each node
If the length of the subtrees below each node + 1 are all divisible by K, then it works; 
if the lengths of the subtrees + 1 that are not divisible by K but can form pairs that add up to K (eg if K = 7, 3 + 4, 2 + 5 etc.), then it also works; 
finally, if the lengths of the subtrees + 1 that are not divisible by K and cannot form pairs are = 1, then it also works
We can find the length of each subtree using dp
Using some mathematical intuition, we can notice that if the total path is N - 1, then we don’t have to check K that is not a divisor of N - 1, since we cannot split the N - 1 paths evenly
This ends up to be O(N * div(N)), where div(N) is the number of divisors of N
Depending on the language/specific details of your algorithm, it may or may not pass the time limit for the star test cases, which may need a separate solution
*/

int N;
vector<vector<int>> adj;
vector<vector<int>> children;
int dp[100000] = {0};
bool visited[100000] = {0};

void dfs(int pos, int par) {
	for (int i = 0; i < adj[pos].size(); i++) {
		int next = adj[pos][i];
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, pos);
			dp[pos] += dp[next] + 1;
		}
	}
	if (par != -1) {
		children[par].push_back(dp[pos] + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
		children.push_back({});
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited[0] = true;
	dfs(0, -1);
	vector<int> divisors;
	for (int i = 1; i < N; i++) {
		if ((N - 1) % i == 0) divisors.push_back(i);
	}
	bool ans[100000] = {0};
	for (int i = 0; i < divisors.size(); i++) {
		bool check = true;
		for (int j = 0; j < N; j++) {
			if (j == 0 || children[j].size() > 1) {
				int paths[100000] = {0};
				int count = 0;
				for (int k = 0; k < children[j].size(); k++) {
					if (children[j][k] % divisors[i] != 0) {
						if (children[j][k] % divisors[i] <= divisors[i] / 2) {
							if (paths[children[j][k] % divisors[i]] < 0 || (divisors[i] % 2 == 0 && children[j][k] % divisors[i] == divisors[i] / 2 && paths[children[j][k] % divisors[i]] % 2 == 1)) {
							    count--;
							}
							else count++;
							paths[children[j][k] % divisors[i]]++;
						}
						else {
							if (paths[divisors[i] - children[j][k] % divisors[i]] > 0) count--;
							else count++;
							paths[divisors[i] - children[j][k] % divisors[i]]--;
						}
					}
				}
				if (count > 1 || (count == 1 && j == 0)) {
					check = false;
					break;
				}
			}
		}
		ans[divisors[i] - 1] = check;
	}
	for (int i = 0; i < N - 1; i++) {
		cout << ans[i];
	}
	cout << endl;
}
