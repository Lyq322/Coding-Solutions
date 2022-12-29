#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// :spiral:

int main() {
	ifstream fin("balance.in");
	ofstream fout("balance.out");
	int N;
	fin >> N;
	int arr1[100000];
	int arr2[100000];
	vector<int> v1; // 1 one
	vector<int> v2; // 2 one
	vector<int> v3; // 1 zero
	vector<int> v4; // 2 zero
	pair<int, int> a1[100000];
	pair<int, int> a2[100000];

	for (int i = 0; i < N; i++) {
		fin >> arr1[i];
		if (arr1[i] == 1) {
			v1.push_back(N - i - 1);
		}
		else {
			v3.push_back(N - i - 1);
		}
	}
	int cur1 = 0;
	int cur2 = 0;
	for (int i = N - 1; i > -1; i--) {
		if (arr1[i] == 0) {
			cur1++;
		}
		else {
			cur2++;
		}
		a1[i] = {cur1, cur2};
	}
	for (int i = 0; i < N; i++) {
		fin >> arr2[i];
		if (arr2[i] == 1) {
			v2.push_back(i);
		}
		else {
			v4.push_back(i);
		}
	}
	cur1 = 0;
	cur2 = 0;
	for (int i = 0; i < N; i++) {
		if (arr2[i] == 0) {
			cur1++;
		}
		else {
			cur2++;
		}
		a2[i] = {cur1, cur2};
	}
	// initial count
	ll ones1 = 0;
	ll ones2 = 0;
	ll count1 = 0;
	ll count2 = 0;
	for (int i = 0; i < N; i++) {
		if (arr1[i] == 0) {
			count1 += ones1;
		}
		else {
			ones1++;
		}
		if (arr2[i] == 0) {
			count2 += ones2;
		}
		else {
			ones2++;
		}
	}
	ll ans = abs(count1 - count2);
	ll org1 = count1;
	ll org2 = count2;
	ll count = 0;
	ll end = min(ones1, N - ones2);
	ll temp2 = ones2;
	ll temp1 = ones1;
	for (int i = 0; i < end; i++) {
		count += v1[v1.size() - i - 1] + v4[i] + 1;
		count1 -= a1[N - v1[v1.size() - i - 1] - 1].first + i;
		count2 -= a2[v4[i]].second + i;
		count1 += ones1 - 1;
		count2 += N - ones2 - 1;
		ones1--;
		ones2++;
		ans = min(ans, abs(count1 - count2) + count);
	}
	ones1 = temp1;
	ones2 = temp2;
	end = min(ones2, N - ones1);
	count = 0;
	count1 = org1;
	count2 = org2;
	for (int i = 0; i < end; i++) {
		count += v2[i] + v3[v3.size() - i - 1] + 1;
		count1 += a1[N - v3[v3.size() - i - 1] - 1].second + i;
		count2 += a2[v2[i]].first + i;
		count1 -= ones1;
		count2 -= N - ones2;
		ones1--;
		ones2++;
		ans = min(ans, abs(count1 - count2) + count);
	}
	fout << ans << endl;
}
