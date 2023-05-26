#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX_N = 1e5;


vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);

void sieve(){
	is_prime[0] = is_prime[1] = false;
    spf[0] = 0;
    spf[1] = 1;
    
    for(int i = 2; i <= MAX_N; i++){
        spf[i] = i;
    }

    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i){
                is_prime[j] = false;
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorise(int n){
    vector<int> factors;
    while(n != 1){
        int sf = spf[n];
        factors.push_back(sf);
        while(n % sf == 0){
            n /= sf;
        }
    }
    return factors;
}