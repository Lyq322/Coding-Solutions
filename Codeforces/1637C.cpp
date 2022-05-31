#include <iostream>

using namespace std;
typedef long long ll;

ll T, N;
ll num[100000];

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N;
        for (ll j = 0; j < N; j++) {
            cin >> num[j];
        }
        if (N == 3 && num[1] % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        bool b = true;
        for (ll j = 1; j < N - 1; j++) {
            if (num[j] != 1) {
                b = false;
            }
        }
        if (b) {
            cout << -1 << endl;
            continue;
        }
        ll count = 0;
        for (ll j = 1; j < N - 1; j++) {
            count += (num[j] + 1) / 2;
        }
        cout << count << endl;
    }
}