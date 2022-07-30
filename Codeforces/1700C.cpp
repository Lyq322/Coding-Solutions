#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll arr[200000] = {0};
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll a = arr[0];
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				ans += arr[i + 1] - arr[i];
			}
			else if (arr[i] > arr[i + 1]) {
				ans += arr[i] - arr[i + 1];
				a -= arr[i] - arr[i + 1];
			}
		}
		ans += abs(a);
		cout << ans << endl;
	}
}

/*
We need to find out the minimum number of actions needed to make all trees the same moisture level, as then it would be easy to calculate the answer
Let t1 and t2 be two adjacent trees with moisture level of m1 and m2
Notice that if t1 and t2 are different, then there must be an action that only affect one of them (the one with higher moisture level)
Using this we can create a prefix and suffix sum array, and after using ps and ss we get our answer array with all tree with the same level of moisture
*/