#include <bits/stdc++.h>
using namespace std;

/* implementation of some useful random generating functions
*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> random_permutation(int n){
    vector<int> temp(n);
    for(int i = 1; i <= n; i++){
        temp[i - 1] = i;
    }
    shuffle(temp.begin(), temp.end(), rng);
    return temp;
}

/* TODO: 
    - prufer sequence of random tree generation
    - Fisher Yates for random permutation
*/

int main(){
    vector<int> t = random_permutation(5);
    for(auto x: t){
        cout << x << " ";
    }
    cout << "\n";
}