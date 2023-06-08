

/* author: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}

vector<int> factorial(MAX_N + 1, 1);

void pre(){
	for(int i = 1; i <= MAX_N; i++){
		factorial[i] = (i * factorial[i - 1]) % MOD;
	}
}

int ncr(int n, int r){
	int x = factorial[n];
	x *= modinverse(factorial[n - r]);
	x %= MOD;
	x *= modinverse(factorial[r]);
	x %= MOD;
	return x;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}