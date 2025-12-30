/******************************************************************************
Link: ROADS
Code: ROADS
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-15.20.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
int n, m, k;

struct EdgeTo{
    int v, idx;
};
struct Edge{
    int u, v, w;
};

vector<EdgeTo> adj[MAXN + 5];
vector<Edge> edges;

int num[MAXN + 5], low[MAXN + 5];

int order = 0;
bool is_khop[MAXN + 5];
vector<int> cau;
bool is_cau[MAXN + 5];

void dfs(int u, int prev){
    num[u] = low[u] = ++order;
    for(auto [v, idx] : adj[u]){
        if(v == prev) continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > num[u]){
                cau.push_back(idx);
                is_cau[idx] = true;
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}

void solve(){
    int chosen = 0;
    vector<int> pos;
    for(int i: cau){
        pos.push_back(i + 1);
        ++chosen;
    }
    for(int i = 0; i < m; ++i){
        if(!is_cau[i]){
            if(edges[i].w == 0){
                pos.push_back()
            }
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("ROADS.INP","r",stdin);
    //freopen("ROADS.OUT","w",stdout);
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges.push_back({a, b, c});
    }

    for(int i = 1; i <= n; ++i){
        if(!num[i]) dfs(i, i);
    }

    solve();

    return 0;
}
