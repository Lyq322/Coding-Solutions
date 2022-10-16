#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Binary search on answer
Be careful about upperbound of bin search
*/

int N, M;
int chocolate[50000];

bool check(ll m) {
	ll level = 0;
	int index = 0;
	for (int i = 0; i < M; i++) {
		while (level < m) {
			if (index >= N) return false;
			level += chocolate[index];
			index++;
		}
		level /= 2;
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> chocolate[i];
	}
	ll l = 0;
	ll r = 10000000000000;
	ll m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == 10000000000000 || !check(m + 1))) {
			cout << m << endl;
			break;
		}
		else if (check(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
}
