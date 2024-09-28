#include <bits/stdc++.h>
using namespace std;

struct Kosaraju { 
    int n;
    vector<vector<int>> adj, r_adj, cond;
    vector<int> vis, root;
    Kosaraju(int _n, vector<vector<int>>& _adj) {
        n = _n; adj= _adj; r_adj.assign(n, vector<int>());
        scc();
    }

    void dfs(int source, vector<vector<int>>& adj, vector<int>& order){
        vis[source] = true;
        for(auto x: adj[source]) if(!vis[x]){
            dfs(x, adj, order);
        }
        order.push_back(source);
    }

    void scc(){
        vector<int> order;
        vis.assign(n, false);
        for(int i = 0; i < n; i++) if(!vis[i]){
            dfs(i, adj, order);
        }

        vis.assign(n, false);
        for(int i = 0; i < n; i++) {
            for(int x : adj[i])
                r_adj[x].push_back(i);
        }

        vector<int> roots(n, 0);
        for(auto v: order){
            if(!vis[v]){
                vector<int> comp;
                dfs(v, r_adj, comp);
                sort(comp.begin(), comp.end());
                int root = component.front();
                for(auto u: component)
                    roots[u] = root;
           }
        }
    }

    vector<vector<int>> get_condensed(){
        return cond;
    }
    vector<int> get_root(){
        return root;
    }

};


// non struct implementation

vector<bool> visited; 

void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

void strongy_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            sort(component.begin(), component.end());
            components.push_back(component);
            int root = component.front();
            for (auto u : component)
                roots[u] = root;
        }

    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}