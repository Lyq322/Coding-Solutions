#include <iostream>

using namespace std;
typedef long long ll;

ll T, N, X;
ll num[5000];

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N >> X;
        for (ll j = 0; j < N; j++) {
            cin >> num[j];
        }
        ll maximum[5001];
        for (ll j = 0; j < N; j++) {
            maximum[j] = -1000000;
        }
        for (ll j = 1; j <= N; j++) {
            ll t = 0;
            for (ll k = 0; k < j; k++) {
                t += num[k];
            }
            maximum[j] = t;
            for (ll k = j; k < N; k++) {
                t = t + num[k] - num[k - j];
                maximum[j] = max(maximum[j], t);
            }
        }
        for (ll j = 0; j <= N; j++) {
            ll ans = 0;
            for (ll k = 1; k <= N; k++) {
                ans = max(ans, maximum[k] + min(k, j) * X);
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
}