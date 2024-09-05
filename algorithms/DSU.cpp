#include <bits/stdc++.h>
using namespace std;
struct dsu{
	vector<int> parent;
	vector<int> sz;

	void init(int n){
		parent.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b) 
			return 0;
		if(sz[a] < sz[b])
			swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
		return 1;
	}
};