#include <bits/stdc++.h>

using namespace std;

string s;
int N;
int num[200000];
int c[200001];
int o[200001];
int w[200001];

int main() {
	cin >> s;
	//int prev = -1;
	//char prev_char;
	//int t = 0;
	int c_count = 0;
	int o_count = 0;
	int w_count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == 'C') {
			c_count++;
		}
		else if (s.at(i) == 'O') {
			o_count++;
		}
		else {
			w_count++;
		}
		c[i + 1] = c_count;
		o[i + 1] = o_count;
		w[i + 1] = w_count;
	}
	/*ps[0] = 0;
	for (int i = 0; i < s.size(); i++) {
		ps[i + 1] = ps[i] + num[i];
	}*/

	cin >> N;
	int l, r;
	for (int i = 0; i < N; i++) {
		cin >> l >> r;
		int c_num = c[r] - c[l - 1];
		int o_num = o[r] - o[l - 1];
		int w_num = w[r] - w[l - 1];
		if ((o_num + w_num) % 2 != 0) {
			cout << "N";
		}
		else if (o_num % 2 == 0 && c_num % 2 == 0) {
			cout << "N";
		}
		else if (o_num % 2 == 0 && c_num % 2 == 1) {
			cout << "Y";
		}
		else if (o_num % 2 == 1 && c_num % 2 == 0) {
			cout << "Y";
		}
		else {
			cout << "N";
		}
	}
	cout << endl;
}
