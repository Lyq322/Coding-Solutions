#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
First notice that the graph of the sample case is a fractal pattern –
	x  x
	 x
	x  x
	and repeats infinitely
Now we can forget about the floor division and all the math stuff :D
The answer is basically diagonal to (x + d, y + d) - diagonal to (x - 1, y - 1)
Let function f(diff, k) calculate the # of X in the diagonal with difference diff (abs value works since the graph is symmetric) and within the square from (0, 0) to (3^k, 3^k) (start inclusive, end exclusive)
	Notice that we can calculate this recursively
		For the sample case, when k = 1 (square with length 3), we have
		1 0 3 0 1
		For the next k = 2 (square with length 9), we have
		1 0 3 0 1 0 3 0 9 0 3 0 1 0 3 0 1
		Clearly there’s a pattern
	Turns out the formula for calculating the next k is
		If diff < 3^(k - 1)
		f(diff, k) = 3 * f(diff, k - 1)
		If its equal
		f(diff, k) = 0
		Else
		f(diff, k) = f(abs(diff - 2 * 3^(k - 1)), k - 1)
	This can be calculated in O(N)
Now we can start calculating when (x, y) doesn’t end exactly on a 3^k square, also using a recursion
	We want to be able to transition from k to k - 1, so first look for a similarity between those two for a given diagonal from (x - min(x, y), y - min(x, y)) to (x, y), or (x - y, 0) to (x, y) if we assume x is greater (swap if y is greater)
	x  x    ABC
      x     DEF - naming for later
	x  x    GHI
	We can split into cases for where (x - y, 0) is and where (x, y) is on the 9 possible locations on the “diagram” above
	For (start, end):
		(B, B) -> 0
		(B, C) -> partial(k - 1)
		(B, F) -> full(k - 1)
		(A, A) -> partial(k - 1)
		(A, B) -> full(k - 1)
		(A, E) -> full(k - 1) + partial(k - 1)
		(A, F) -> 2 * full(k - 1)
		(A, I) -> 2 * full(k - 1) + partial(k - 1)
*/

ll full[40];
ll powers[40];
ll solve_full(ll diff, int k) {
	if (full[k] != -1) return full[k];
	if (k == 0) {
		if (diff == 0) full[k] = 1;
		else full[k] = 0;
		return full[k];
	}
	if (diff < powers[k - 1]) {
		return full[k] = 3 * solve_full(diff, k - 1);
	}
	else if (diff == powers[k - 1]) {
		return full[k] = 0;
	}
	else {
		return full[k] = solve_full(abs(diff - 2 * powers[k - 1]), k - 1);
	}
}

ll solve_not_full(ll x, ll y, int k) {
	if (x < y) swap(x, y);
	if (k == 0) {
		return 1;
	}
	if (x - y >= powers[k - 1]) {
		if (x < 2 * powers[k - 1]) return 0;
		else if (y < powers[k - 1]) return solve_not_full(x % powers[k - 1], y % powers[k - 1], k - 1);
		else return full[k - 1];
	}
	else {
		if (x < powers[k - 1]) return solve_not_full(x % powers[k - 1], y % powers[k - 1], k - 1);
		else if (y < powers[k - 1]) return full[k - 1];
		else if (x < 2 * powers[k - 1]) return full[k - 1] + solve_not_full(x % powers[k - 1], y % powers[k - 1], k - 1);
		else if (y < 2 * powers[k - 1]) return 2 * full[k - 1];
		else return 2 * full[k - 1] + solve_not_full(x % powers[k - 1], y % powers[k - 1], k - 1);
	}
}

ll solve(ll x, ll y) {
	if (x < 0 || y < 0) return 0;
	for (int i = 0; i < 40; i++) {
		full[i] = -1;
	}
	solve_full(abs(x - y), 39);
	for (int i = 0; i < 40; i++) {
		if (full[i] == -1) full[i] = 0;
	}
	return solve_not_full(max(x, y), min(x, y), 39);
}

int main() {
	int N;
	ll d, x, y;
	cin >> N;
	powers[0] = 1;
	for (int i = 1; i < 40; i++) {
		powers[i] = powers[i - 1] * 3;
	}
	for (int i = 0; i < N; i++) {
		cin >> d >> x >> y;
		cout << solve(x + d, y + d) - solve(x - 1, y - 1) << endl;
	}
}
