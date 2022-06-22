#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1000] = {0};
	int arr_sorted[1000] = {0};
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr_sorted[i] = arr[i];
	}
	sort(arr_sorted, arr_sorted + N);
	// 1 2, 2 1, 1 3, 3 1, 2 3, 3 2
	int swap[6] = {0};
	int f[6] = {1, 2, 1, 3, 2, 3};
	int s[6] = {2, 1, 3, 1 ,3, 2};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i] == f[j] && arr_sorted[i] == s[j]) {
				swap[j]++;
				break;
			} 
		}
	}
	int ans = 0;
	int a = min(swap[0], swap[1]);
	int b = min(swap[2], swap[3]);
	int c = min(swap[4], swap[5]);
	ans += a + b + c;
	swap[0] -= a;
	swap[1] -= a;
	swap[2] -= b;
	swap[3] -= b;
	swap[4] -= c;
	swap[5] -= c;
	// 1 2, 2 3, 3 1
	a = min(min(swap[0], swap[4]), swap[3]);
	swap[0] -= a;
	swap[3] -= a;
	swap[4] -= a;
	ans += a * 2;
	// 1 3, 3 2, 2 1
	b = min(min(swap[1], swap[2]), swap[5]);
	swap[1] -= b;
	swap[2] -= b;
	swap[5] -= b;
	ans += b * 2;
	for (int i = 0; i < 6; i++) {
		ans += swap[i];
	}
	cout << ans << endl;
}
