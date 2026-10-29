#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)

class LCA{
public:
    int n,LOG=31;
    vector<vector<int>>adj,up;
    vector<int>depth;
    void init(int _n){
        n=_n;
        up.assign(LOG,vector<int>(n,-1));
        depth.assign(n,0);
    }
    void dfs(int u,int p){
        up[0][u]=p;
        for(int j=1;j<LOG;++j)
            if(up[j-1][u]!=-1)
                up[j][u]=up[j-1][up[j-1][u]];
        for(int v:adj[u]){
            if(v==p)
                continue;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
    int kth(int u,int k){
        for(int j=0;j<LOG;++j){
            if(k&(1LL<<j)){
                u=up[j][u];
                if(u==-1)
                    break;
            }
        }
        return u;
    }
    void bld(vector<vector<int>>&_adj,int root=0){
        adj=_adj;
        dfs(root,-1);
    }
    int get_lca(int u,int v){
        if(depth[u]<depth[v])
            swap(u,v);
        u=kth(u,depth[u]-depth[v]);
        if(u==v)
            return u;
        for(int j=LOG-1;j>=0;--j)
            if(up[j][u]!=up[j][v])
                u=up[j][u],v=up[j][v];
        return up[0][u];
    }
};

class Fenwick{
public:
    int n;
    vector<int>bit;
    void init(int _n) {
        n=_n;
        bit.assign(n+2,0);
    }
    void upd(int idx,int val) {
        for(++idx;idx<=n;idx+=idx&-idx)
            bit[idx]^=val;
    }
    int qry(int idx){
        int res=0;
        for(++idx;idx>0;idx-=idx&-idx)
            res^=bit[idx];
        return res;
    }
    void range_upd(int l,int r,int val) {
        upd(l,val);
        if (r+1<n)
            upd(r+1,val);
    }
};

class Solution {
public:
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        tin[u] = timer++;

        for (int v : adj[u])
            if (v != p)
                dfs(v, u);

        tout[u] = timer - 1;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& E, string s, vector<string>& Q) {
        adj.assign(n, {}), tin.assign(n, 0), tout.assign(n, 0), timer = 0;

        for (auto& e : E) {
            int u = e[0], v = e[1];
            adj[u].push_back(v), adj[v].push_back(u);
        }

        dfs(0, -1);

        Fenwick fenwick;
        fenwick.init(n);

        LCA lca;
        lca.init(n), lca.bld(adj);

        for (int u = 0; u < n; ++u)
            fenwick.range_upd(tin[u], tout[u], 1 << (s[u] - 'a'));

        int q = Q.size();
        vector<bool> res;

        for (int i = 0; i < q; ++i) {
            istringstream ss(Q[i]);
            string op, U, V;

            ss >> op >> U >> V;
            int u = stoi(U);

            if (op == "update") {
                char ch = V[0];
                int delta = (1 << (s[u] - 'a')) ^ (1 << (ch - 'a'));
                fenwick.range_upd(tin[u], tout[u], delta), s[u] = ch;
            }

            else {
                int v = stoi(V), uv_lca = lca.get_lca(u, v);
                int mask = fenwick.qry(tin[u]) ^ fenwick.qry(tin[v]) ^ (1 << (s[uv_lca] - 'a'));
                res.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return res;
    }
};