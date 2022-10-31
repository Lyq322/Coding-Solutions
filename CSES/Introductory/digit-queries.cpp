#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		ll t = 0;
		ll count = 9;
		ll i = 1;
		while (t + count <= N) {
			t += count;
			count = (i + 1) * 9 * (ll) pow(10, i);
			i++;
		}
		N -= t;
		if (N == 0) {
			cout << 9 << endl;
			continue;
		}
		ll b = (N + i - 1) / i;
		string a = to_string(b + (ll) pow(10, i - 1) - 1);
		cout << a[N - (b - 1) * i - 1] << endl;
	}
}
