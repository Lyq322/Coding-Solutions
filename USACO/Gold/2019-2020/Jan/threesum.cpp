#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// If we can make an 2D-array values, where values[i][j] is the number of valid 3SUM with first value being arr[i] and second value being arr[j], then we can use a 2D prefix sum to calculate the answer

int main() {
	ifstream fin("threesum.in");
	ofstream fout("threesum.out");
	int N, M;
	fin >> N >> M;
	int arr[5000];
	for (int i = 0; i < N; i++) {
		fin >> arr[i];
	}
	ll count[5001][5001] = {{0}};
	int arr2[2000001] = {0};
	for (int i = 0; i <= N - 3; i++) {
		int cur = arr[i];
		for (int j = i + 1; j < N; j++) {
			arr2[arr[j] + 1000000]++;
		}
		for (int j = N - 1; j >= i + 2; j--) {
			int c = - cur - arr[j];
			arr2[arr[j] + 1000000]--;
			if (c >= -1000000 && c <= 1000000) count[i + 1][j + 1] = arr2[c + 1000000];
		}
		arr2[arr[i + 1] + 1000000]--;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			count[i][j] += count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
		}
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		fin >> a >> b;
		fout << count[N][b] - count[a - 1][b] << endl;
	}
}
