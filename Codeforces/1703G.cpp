#include <bits/stdc++.h>
using namespace std;

int main() {
	long long T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		long long arr[100000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long ans = 0;
		long long cur = 0;
		long long good_keys = 0;
		for (int i = 0; i <= n; i++) {
			cur = good_keys;
			for (int j = i; j < min(i + 31, n); j++) {
				long long temp = arr[j] >> (j - i + 1);
				cur += temp;
			}
			ans = max(ans, cur);
			if (i != n) good_keys += arr[i] - m;
		}
		cout << ans << endl;
	}
}

/*
Notice that we will use good keys for the first x times, and bad keys for the rest
This means we can loop over the point where we switch from good to bad in O(N)
We can keep track of the number of coins we get from the good keys along with the loop
For the bad keys, notice that after log2(10^9) < 30 times we use a bad key, all of chests left will have 0 coins
This means for the bad keys, we only need to check either until N or the next 30 keys, whichever one is smaller. 
*/