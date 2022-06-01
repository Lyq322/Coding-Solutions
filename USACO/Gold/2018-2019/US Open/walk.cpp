#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
bool visited[7500] = {0};
ll mst[7500] = {0};

ll dist(ll i, ll j) {
	ll a = ((2019201913 * (min(i, j) + 1)) % 2019201997) + ((2019201949 * (max(i, j) + 1)) % 2019201997);
	a = a % 2019201997; 
	return a;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		mst[i] = -1;
	}
	priority_queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < N; i++) {
			if (!visited[i] && i != cur && (mst[i] == -1 || mst[i] > dist(i, cur))) {
				mst[i] = dist(i, cur);
				q.push(i);
			}
		}
	}
	sort(mst, mst + N);
	cout << mst[N - K + 1] << endl;
}

/*
Idea
	Input can be represented using graphs
		NOT through adj vector/list as it will exceed the time limit
	A regular MST simulates when K = 1, or when there is only one connected component
		The edges of the MST show the nodes that are connected, i.e. the edges of the MST do not need to be counted when calculating the ans/minimum
	When you “cut” N edges of a tree, there will be N + 1 connected components
		⇒ Cut K - 1 edges (not use those edges) with the HIGHEST edge weight of the MST to get K connected components with the minimum edge weight connecting to them
*/