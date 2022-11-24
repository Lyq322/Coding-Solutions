#include <bits/stdc++.h>
using namespace std;

ifstream fin;
ofstream fout;

int main() {
	fin.open("cardgame.in");
	fout.open("cardgame.out");
	int N;
	fin >> N;
	int elsie[50000];
	int copy[50000];
	for (int i = 0; i < N; i++) {
		fin >> elsie[i];
		copy[i] = elsie[i];
	}
	sort(copy, copy + N);
	sort(elsie, elsie + N / 2);
	sort(elsie + N / 2, elsie + N);
	int j = 0;
	int bessie[50000];
	for (int i = 0; i < 2 * N; i++) {
		if (j == N || copy[j] != i + 1) {
			bessie[i - j] = i + 1;
		}
		else {
			j++;
		}
	}
	int i = 0;
	j = N / 2;
	int ans = 0;
	while (i < N / 2 && j < N) {
		if (elsie[i] < bessie[j]) {
			ans++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	i = N / 2;
	j = 0;
	while (i < N && j < N / 2) {
		if (elsie[i] > bessie[j]) {
			ans++;
			i++;
			j++;
		}
		else {
			i++;
		}
	}
	fout << ans << endl;
}
