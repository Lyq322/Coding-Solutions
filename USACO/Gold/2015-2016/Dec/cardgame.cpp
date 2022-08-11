#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr1[25000];
	int arr2[25000];
	bool all_num[100000] = {0};
	for (int i = 0; i < N / 2; i++) {
		cin >> arr1[i];
		arr1[i]--;
		all_num[arr1[i]] = true;
	}
	for (int i = 0; i < N / 2; i++) {
		cin >> arr2[i];
		arr2[i]--;
		all_num[arr2[i]] = true;
	}
	sort(arr1, arr1 + N / 2);
	sort(arr2, arr2 + N / 2);
	int left[50000];
	int index = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (!all_num[i - 1]) {
			left[index] = i - 1;
			index++;
		}
	}
	int ans = 0;
	int i = 0;
	int j = N / 2;
	while (i < N / 2 && j < N) {
		if (arr1[i] < left[j]) {
			ans++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	i = 0;
	j = 0;
	while (i < N / 2 && j > -1) {
		if (arr2[i] < left[j]) {
			i++;
		}
		else {
			ans++;
			i++;
			j++;
		}
	}
	cout << ans << endl;
}
