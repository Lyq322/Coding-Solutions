#include <bits/stdc++.h>

using namespace std;

int t;

void solve() {
    int n;
    vector<int> a;
    vector<int> b;
    cin >> n;
    int num;
    int maximum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
        sum += num;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
        sum += num;
    }
    bool dp[101][20010] = {{0}};
    dp[1][a[0]] = true;
    dp[1][b[0]] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= a[i - 1] && dp[i - 1][j - a[i - 1]]) {
                dp[i][j] = true;
            } 
            else if (j >= b[i - 1] && dp[i - 1][j - b[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }
    int ans = 0x7FFFFFFF;
    for (int i = sum / 2; i <= sum; i++) {
        if (dp[n][i]) {
            ans = min(ans, i * i + (sum - i) * (sum - i));
        }
    }
    for (int i = 0; i < n; i++) {
        ans += (n - 2) * (a[i] * a[i] + b[i] * b[i]);
    }
    cout << ans << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}