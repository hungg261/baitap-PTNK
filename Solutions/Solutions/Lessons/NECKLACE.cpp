#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50;
multiset<int> adj[MAXN + 5];
int n, m;

bool check1(){
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() & 1) return false;
    }
    return true;
}

bool check2(){
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() > 0) return false;
    }
    return true;
}

vector<int> res;
void dfs(int u){
    while(!adj[u].empty()){
        int v = *adj[u].begin();
        adj[u].erase(adj[u].find(v));
        adj[v].erase(adj[v].find(u));

        dfs(v);
    }

    res.push_back(u);
}

void solve(){
    cin >> m;

    for(int i = 1; i <= 50; ++i) adj[i].clear();
    res.clear();
    n = 0;

    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);

        n = max({n, a, b});
    }

    if(!check1()){
        cout << "NO\n";
        return;
    }

    dfs(n);

    if(!check2()){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = 0; i < (int)res.size() - 1; ++i){
        cout << res[i] << ' ' << res[i + 1] << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NECKLACE.INP","r",stdin);
    freopen("NECKLACE.OUT","w",stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
