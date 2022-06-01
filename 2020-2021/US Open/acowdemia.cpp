#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, L;
ll papers[100000];

bool check(ll h) {
	ll papersNeeded = 0;
	ll citationsNeeded = 0;
	for (ll i = N - 1; i > N - h - 1; i--) {
		if (papers[i] >= h) {
			continue;
		}
		else {
			papersNeeded = max(papersNeeded, h - papers[i]);
			citationsNeeded += h - papers[i];
		}
	}
	if (papersNeeded > K) {
		return false;
	}
	else if (citationsNeeded > K * L) {
		return false;
	}
	return true;
}

int main() {
	cin >> N >> K >> L;
	for (ll i = 0; i < N; i++) {
		cin >> papers[i];
	}
	sort(papers, papers + N);
	ll L = 0;
	ll R = N;
	ll M;
	while (L < R) {
		M = L + (R - L + 1) / 2;;
		if (check(M)) {
			L = M;
		}
		else {
			R = M - 1;
		}
	}
	cout << L << endl;
}
