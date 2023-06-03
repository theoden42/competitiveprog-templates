#include <bits/stdc++.h>
using namespace std;


struct dsu{
	vector<int> parent;
	vector<int> sz;

	void init(int n){
		parent.resize(n);
		size.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(x)); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)return;

		if(sz[a] < sz[b])
			swap(a, b);

		parent[b] = a;
		sz[a] += sz[b];
	}

}