#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int adj[1000][2];
	for (int i = 0; i < N; i++) {
		cin >> adj[i][0] >> adj[i][1];
		adj[i][0]--;
		adj[i][1]--;
	}
	int dir[500];
	char c;
	for (int i = 0; i < M; i++) {
		cin >> c;
		if (c == 'L') dir[i] = 0;
		else dir[i] = 1;
	}
	int visited[1000] = {0};
	int pos = 0;
	vector<int> v;
	for (int k = 0; k <= K; k++) {
		if (visited[pos] != 0) break;
		visited[pos] = k;
		v.push_back(pos);
		for (int i = 0; i < M; i++) {
			pos = adj[pos][dir[i]];
		}
	}
	if (v.size() == K + 1) {
		cout << v[v.size() - 1] + 1 << endl;
	}
	else {
		K -= visited[pos];
		cout << v[visited[pos] + K % (v.size() - visited[pos])] + 1 << endl;
	}
}

/*
We cannot simulate all K’s since K is too large
However we know that after one cycle of the M directions, it must land on one of the N ports, and N is only 1000
This means we can simulate the minimum of these, all ports before we come to a cycle, or when we have reached K
We can use a visited array to keep track of which port is visited
Another vector array to track the already visited ports in the order they are visited
To find the final destination if it is case 1
*/