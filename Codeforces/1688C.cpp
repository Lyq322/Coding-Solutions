#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int z = 0; z < T; z++) {
		cin >> N;
		string s;
		cin.ignore();
		int arr[26] = {0};
		for (int i = 0; i < 2 * N; i++) {
			getline(cin, s);
			for (int j = 0; j < s.size(); j++) {
				arr[s.at(j) - 97]++;
			}
		}
		string final_s;
		getline(cin, final_s);
		for (int j = 0; j < final_s.size(); j++) {
			arr[final_s.at(j) - 97]++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 1) {
				cout << alphabet.at(i) << endl;
			}
		}
	}
}

/*
The initial char will appear in an odd number of times in all of the input strings, including the final string
Everything else will appear in an even number of times
*/