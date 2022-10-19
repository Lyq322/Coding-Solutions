#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
For each A, we will have some number of loops
Notice that the steps K needed for each A is just the lcm of the lengths of all loops
We can just make every length relatively prime to each other since this conserves space and doesn’t change the answer
Therefore the problem is essentially asking for the sum of numbers that satisfy:
N = p1^a1 * p2^a2 * p3*a^3 … pn^an (prime factorization)
Sum of p1^a1 + p2^a2 + … + pn^an is ≤ N
To solve this, we use dp of course D:
Knapsack-ish dp, where dp[i][j] is defined as the sum of K (mod M) when we use the first i primes and take up j spaces (out of N, since the sum of the powers of the primes is ≤ N)
To calculate each dp state, we need to look at the previous prime (dp[i - 1]) and check all j - (cur_prime^k) by looping through k
The formula would then be dp[i][j] = dp[i - 1][j] (not containing cur prime) + dp[i - 1][j - cur_prime^k] * k (containing cur prime, * k since lcm of relative primes is just multiplication)
*/

int main() {
	int N, M;
    cin >> N >> M;
    vector<ll> primes;
    for (int i = 2; i <= N; i++) {
        bool b = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                b = false;
                break;
            }
        }
        if (b) {
            primes.push_back(i);
        }
    }
    ll dp[2][100001];
    dp[0][0] = 0;
    ll cur = 1;
    for (int i = 1; i <= N; i++) {
        if (i == cur) {
            dp[0][i] = dp[0][i - 1] + cur;
            cur = cur * 2;
        }
        else dp[0][i] = dp[0][i - 1];
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < primes.size(); i++) {
        for (int j = 1; j <= N; j++) {
            ll p = primes[i];
            dp[i % 2][j] = dp[(i + 1) % 2][j];
            while (j - p >= 0) {
                dp[i % 2][j] = (dp[i % 2][j] + (dp[(i + 1) % 2][j - p] * p) % M) % M;
                p = (p * primes[i]) % M;
            }
        }
    }
    cout << dp[(primes.size() + 1) % 2][N] << endl;
}
