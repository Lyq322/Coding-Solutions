#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

ll T, N, X;

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N >> X;
        multiset<ll> s;
        ll a;
        for (ll j = 0; j < N; j++) {
            cin >> a;
            s.insert(a);
        }
        ll ans = 0;
        while (!s.empty()) {
            ll first = *s.begin();
            if (s.find(first * X) == s.end()) {
                ans++;
                s.erase(s.begin());
            }
            else {
                s.erase(s.find(first * X));
                s.erase(s.begin());
            }
        }
        cout << ans << endl;
    }
}