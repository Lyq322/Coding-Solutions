#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N;
map<string, ll> sToll;


int main() {
    cin >> N;
    string s;
    ll index = 0;
    ll cows[1000][3];
    ll compare[1000];
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < 3; j++) {
            cin >> s;
            if (sToll.find(s) == sToll.end()) {
                sToll[s] = index;
                cows[i][j] = index;
                index++;
            }
            else {
                cows[i][j] = sToll[s];
            }
        }
        ll temp[3] = {cows[i][0], cows[i][1], cows[i][2]};
        sort(temp, temp + 3);
        compare[i] = 3000 * 3000 * temp[0] + 3000 * temp[1] + temp[2];
    }
    sort(compare, compare + N);
    ll count = 0;
    ll prev = compare[0];
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (compare[i] == prev) {
            count++;
        }
        else {
            ans = max(ans, count);
            count = 1;
            prev = compare[i];
        }
    }
    ans = max(ans, count);
    cout << ans << endl;
}