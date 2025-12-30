/******************************************************************************
Link: PROGRAM
Code: PROGRAM
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-14.43.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
vector<int> adj[MAXN + 5];
int w[MAXN + 5];
int n, m;

bool mark[MAXN + 5];
vector<int> topo;
void dfs(int u){
    if(mark[u]) return;
    mark[u] = true;

    for(int v: adj[u]){
        dfs(v);
    }

    topo.push_back(u);
}

int dp[MAXN + 5], res[MAXN + 5];
void solve(){
    for(int i = 1; i <= n; ++i) dfs(i);
    reverse(begin(topo), end(topo));

    int ans = 0;
    for(int u: topo){
        ans = max(ans, dp[u] + w[u]);
        for(int v: adj[u]){
            dp[v] = max(dp[v], dp[u] + w[u]);
        }
    }

    cout << ans << '\n';
    for(int u = 1; u <= n; ++u){
        cout << dp[u] + 1 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PROGRAM.INP","r",stdin);
    freopen("PROGRAM.OUT","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    solve();

    return 0;
}
