#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;

ll T;
ll N;
ll ans = 100;

void choose(string s) {
    if (s.size() == 14) {
        ll count = 0;
        ll f = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (s.at(i) == '1') {
                f++;
                ll c = 1;
                for (ll j = 1; j <= i + 1; j++) {
                    c *= j;
                }
                count += c;
            }
        }
        if (count > N) {
            return;
        }
        ll t = N - count;
        count = 0;
        while (t > 0) {
            count++;
            t = t & (t - 1);
        }
        if (ans > count + f) {
            ans = count + f;
        }
        return;
    }
    choose(s + '0');
    choose(s + '1');
    
}

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N;
        ans = 100;
        choose("");
        cout << ans << endl;
    }
}