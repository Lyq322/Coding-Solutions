#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, N;
	cin >> L >> N;
	pair<int, int> arr[100001];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	arr[N] = {L, 2000000000};
	sort(arr, arr + N + 1);
	for (int i = N - 2; i > -1; i--) {
		if (arr[i].second - arr[i + 1].second > arr[i + 1].first - arr[i].first) {
			arr[i].second = arr[i + 1].second + arr[i + 1].first - arr[i].first;
		}
	}
	int cur_speed = 1;
	int prev_pos = 0;
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		int dist = arr[i].first - prev_pos;
		if (cur_speed + dist <= arr[i].second) {
			ans = max(ans, cur_speed + dist);
			cur_speed += dist;
			prev_pos = arr[i].first;
			continue;
		}
		int max_speed = (dist + arr[i].second + cur_speed) / 2;
		ans = max(max_speed, ans);
		cur_speed = arr[i].second;
		prev_pos = arr[i].first;
	}
	cout << ans << endl;
}

/*
Let two speed limits be x and y, and their distance be d_x and d_y, respectively. 
Three cases
	Normal - 1. at speed x when we passed the first limit, 2. Increase speed to a certain point, 3. Decrease speed, 4. Reach the second speed limit at a speed of y
	Too slow (needs x < y) -  1. At speed x when we passed the first limit, 2. However because the distance between the two speed limits is too short for us to increase speed to y, 3. We passed the second speed limit at a speed < y (ie. x < y, d_y - d_x < y - x)
	Too quick (needs x > y) - 1. At speed x when we passed the first limit, 2. However because the dist between the two speed limits is too short for us the decrease to speed y at the speed limit, 3. We cannot have a speed of x at the first speed limit, even though the limit is at x
We can get rid of the third case by adjusting all speed limits beforehand (ie. decreasing speed limit of the ones that satisfy case 3)
For case 2, we can maintain a current speed var
Math!
*/