#include <bits/stdc++.h>
using namespace std;

/*
9/10 :(
Define left_dp[i] as the minimum R needed to for the explosion of i to explode all haybales left of i; define right_dp[i] similarly
	For each haybale, it’s either going to be greater than or equal to the previous haybale
	The current haybale could cause the immediate left (right) haybale to explode, but it could also skip it and explode more haybales to the left (right)
	This means we can keep a separate pointer for the haybale that the current haybale is going to explode immediately with its range, and increment it separately than the current haybale
*** this part is not correct — we can calculate the final answer by finding the answer when the initial explosion is only aimed at one barrel vs when its aimed at two (aimed at the position in the middle -> maybe .5)
	Wrong answer bc the first explosion could be for 2 not adjacent barrels
*/

ifstream fin;
ofstream fout;

int main() {
	fin.open("angry.in");
	fout.open("angry.out");
	int N;
	vector<int> v;
	fin >> N;
	int a;
	int arr[50000];
	for (int i = 0; i < N; i++) {
		fin >> arr[i];
		a = arr[i];
		v.push_back(2 * a);
	}
	sort(arr, arr + N);
	sort(v.begin(), v.end());
	int left_dp[50000] = {0};
	int right_dp[50000] = {0};
	int j = 0;
	for (int i = 1; i < N; i++) {
		bool b = false;
		while (left_dp[j] + 2 < v[i] - v[j]) {
			if (i == j + 1) {
				left_dp[i] = v[i] - v[j];
				b = true;
			}
			j++;
		}
		if (!b) {
			left_dp[i] = left_dp[j] + 2;
		}
	}
	reverse(v.begin(), v.end());
	j = 0;
	for (int i = 1; i < N; i++) {
		bool b = false;
		while (right_dp[N - j - 1] + 2 < v[j] - v[i]) {
			if (i == j + 1) {
				right_dp[N - i - 1] = v[j] - v[i];
				b = true;
			}
			j++;
		}
		if (!b) {
			right_dp[N - i - 1] = right_dp[N - j - 1] + 2;
		}
	}
	int ans = 1000000000;
	for (int i = 0; i < N; i++) {
		ans = min(ans, max(left_dp[i], right_dp[i]));
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++) {
		ans = min(ans, max((v[i + 1] - v[i]) / 2, max(left_dp[i], right_dp[i + 1]) + 2));
	}
	if (ans % 2 == 0) {
		fout << ans / 2 << ".0" << endl;
	}
	else {
		fout << ans / 2 << ".5" << endl;
	}
}
