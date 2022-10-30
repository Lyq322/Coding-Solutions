#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	int mod = 1000000007;
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		ans = (ans * 2) % mod;
	}
	cout << ans << endl;
}
