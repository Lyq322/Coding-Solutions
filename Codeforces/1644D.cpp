#include <iostream>

using namespace std;
typedef long long ll;

ll T;
ll N, M, K, Q;

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N >> M >> K >> Q;
        pair<ll, ll> num[200000];
        for (ll j = 0; j < Q; j++) {
            cin >> num[j].first >> num[j].second;
            num[j].first--;
            num[j].second--;
        }
        bool row[200000] = {0};
        bool col[200000] = {0};
        ll r = 0;
        ll c = 0;
        ll colors = 0;
        for (ll j = Q - 1; j > -1; j--) {
            if (!row[num[j].first] && c != M) {
                r++;
                row[num[j].first] = true;
                colors++;
                if (!col[num[j].second]) {
                    col[num[j].second] = true;
                    c++;
                }
            }
            else if (!col[num[j].second] && r != N) {
                c++;
                col[num[j].second] = true;
                colors++;
                if (!row[num[j].first]) {
                    row[num[j].first] = true;
                    r++;
                }
            }
        }
        ll ans = 1;
        for (ll j = 0; j < colors; j++) {
            ans *= K;
            ans = ans % 998244353;
        }
        cout << ans << endl;
    }
}