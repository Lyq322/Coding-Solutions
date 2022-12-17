#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");
	int N;
	fin >> N;
	int a[100000];
	for (int i = 0; i < N; i++) {
		fin >> a[i];
	}
	bool zero = false;
	int index = N;
	for (int i = 0; i < N; i++) {
		if (a[i] == 0) {
			zero = true;
		}
		else if (zero) {
			index = i;
			break;
		}
	}
	int arr[100000];
	for (int i = 0; i < N; i++) {
		arr[i] = a[(i + index) % N];
	}
	zero = false;
	int count = 0;
	vector<int> counts;
	for (int i = 0; i < N; i++) {
		if (arr[i] != 0 && zero) {
			zero = false;
			counts.push_back(count);
			count = 0;
		}
		else if (arr[i] == 0) {
			zero = true;
		}
		count += arr[i];
		count--;
	}
	counts.push_back(count);
	int ps[100000];
	ps[counts.size()] = 0;
	int maximum = -1;
	index = 0;
	for (int i = counts.size() - 1; i > -1; i--) {
		ps[i] = ps[i + 1] + counts[i];
		if (ps[i] > maximum) {
			maximum = ps[i];
			index = (counts.size() - i) % counts.size();
		}
	}
	count = 0;
	zero = false;
	ll ans = 0;
	for (int i = N - 1; i > -1; i--) {
		if (arr[i] == 0 && !zero) {
			zero = true;
			count++;
			if (count == index + 1) {
				int new_arr[100000];
				for (int j = 0; j < N; j++) {
					new_arr[j] = arr[(i + 1 + j) % N];
				}
				int need = N - 1;
				for (int j = N - 2; j > -1; j--) {
					while (need >= j && new_arr[j] > 0) {
						ans += (j - need) * (j - need);
						need--;
						new_arr[j]--;
					}
				}
				break;
			}
		}
		else if (arr[i] != 0) zero = false;
	}
	fout << ans << endl;
}
