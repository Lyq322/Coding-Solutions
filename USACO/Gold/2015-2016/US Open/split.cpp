#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

bool comp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	int N;
	cin >> N;
	pii arr[50000];
	ll xmin = 1000000000;
	ll xmax = 0;
	ll ymin = 1000000000;
	ll ymax = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		xmin = min(xmin, arr[i].first);
		ymin = min(ymin, arr[i].second);
		xmax = max(xmax, arr[i].first);
		ymax = max(ymax, arr[i].second);
	}
	sort(arr, arr + N);
	ll x_left[50000];
	ll x_right[50000];
	ll min_y = arr[0].second;
	ll max_y = arr[0].second;
	for (int i = 0; i < N; i++) {
		min_y = min(min_y, arr[i].second);
		max_y = max(max_y, arr[i].second);
		x_left[i] = max_y - min_y;
	}
	min_y = arr[N - 1].second;
	max_y = arr[N - 1].second;
	for (int i = N - 1; i > -1; i--) {
		min_y = min(min_y, arr[i].second);
		max_y = max(max_y, arr[i].second);
		x_right[i] = max_y - min_y;
	}
	ll ans = 1000000000000000000;
	for (int i = 0; i < N - 1; i++) {
		ll left = x_left[i] * (arr[i].first - arr[0].first);
		ll right = x_right[i + 1] * (arr[N - 1].first - arr[i + 1].first);
		ans = min(ans, left + right);
	}
	ll y_up[50000];
	ll y_down[50000];
	sort(arr, arr + N, comp);
	ll min_x = arr[0].first;
	ll max_x = arr[0].first;
	for (int i = 0; i < N; i++) {
		min_x = min(min_x, arr[i].first);
		max_x = max(max_x, arr[i].first);
		y_down[i] = max_x - min_x;
	}
	min_x = arr[N - 1].first;
	max_x = arr[N - 1].first;
	for (int i = N - 1; i > -1; i--) {
		min_x = min(min_x, arr[i].first);
		max_x = max(max_x, arr[i].first);
		y_up[i] = max_x - min_x;
	}
	for (int i = 0; i < N - 1; i++) {
		ll down = y_down[i] * (arr[i].second - arr[0].second);
		ll up = y_up[i + 1] * (arr[N - 1].second - arr[i + 1].second);
		ans = min(ans, up + down);
	}
	cout << (ymax - ymin) * (xmax - xmin) - ans << endl;
}

/*
The two fields cannot overlap, so the arrangement must be either top and bottom or left and right
Eg left and right fields
 _    _
|_|  |_|
Notice that there are only N ways for left and right fields and N ways for up and down fields since there is no reason to not have a cow on a field’s boundary
Therefore we can loop through and try everything
This can be done in O(NlogN) (sorting) by precomputing the min and max values of either x or y coordinates of each field
*/