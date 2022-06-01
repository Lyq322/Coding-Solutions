#include <iostream>
#include <map>

using namespace std;

int N, K;
int cows[50000];
map<int, int> pairs;

int main() {
    cin >> N >> K;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        if (pairs.find(cows[i]) == pairs.end()) {
            pairs[cows[i]] = i;
        }
        else {
            if (i - pairs[cows[i]] > K) {
                pairs[cows[i]] = i;
            }
            else {
                ans = max(ans, cows[i]);
                pairs[cows[i]] = i;
            }
        }
    }
    cout << ans << endl;
}