#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N;
	cin >> N;
	ll five = 5;
	int ans = 0;
	while (five <= N) {
		ans += N / five;
		five *= 5;
	}
	cout << ans << endl;
}
