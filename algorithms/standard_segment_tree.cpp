/* author: (g)theoden42 */
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden; // define the identity element herw
   
	T combine(T a, T b){
 	    T temp;	
        // how to combine two nodes
 		return temp ;
 	}
 	T single_value(T v){
    	T temp;
        // what to store in leaves corresponding to array value v
 		return temp;
 	}
    
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, iden);
	}

	void build(vector<T>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind, T value){
		setUtil(ind, value, 0, 0, sz);
	}

	T get(int l, int r){
		return getUtil(l, r, 0, 0, sz);
	}

	void build(vector<T>& a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx]);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}

	T getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
        T left = getUtil(l, r, 2 * x + 1, lx, m);
		T right = getUtil(l, r, 2 * x + 2, m, rx);
		return combine(left, right);
	}

	void setUtil(int ind, T val, int x, int lx, int rx){
		if(rx - lx == 1){
			arr[x] = single_value(val);
			return;
		}

		int m = (lx + rx) / 2;
		if(ind < m){
			setUtil(ind, val, 2 * x + 1, lx, m);
		}
		else{
			setUtil(ind, val, 2 * x + 2, m, rx);
		}

		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}
};
