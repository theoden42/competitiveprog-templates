#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 1e5;
vector<bool> is_prime(MAX_N + 1, false);;
vector<int> primes;

void sieve(){
	is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    for(ll i = 1; i <= MAX_N; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}