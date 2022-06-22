#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int arr[10000];
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + K);
	int ans = max(arr[0], N - arr[K - 1]);
	for (int i = 0; i < K - 1; i++) {
		ans = max(ans, (arr[i + 1] - arr[i]) / 2);
	}
	cout << ans << endl;
}

/*
To simplify this problem, we can first assume K = 1
	Some examples
	Bessie: T T T T T F F F
	FJ:     F F F T T T T T
	Or
	T T F F F F F F
	F F F F F F T T
By trying some examples, we can get that the formula to calculate the minimum score when we know that there are t true questions and fj answers j false is abs(j - t)
Now, for when K > 1, we want to maximize the minimum of abs(j - t_x), looping over all t_x
Notice that abs(j - t_x) is the same as the distance between j and t_x on a number line
Observation: we only need to check the neighbor’s closest to j on the number line to find the minimum of all abs(j - t_x)
O(N log N) for sorting
*/