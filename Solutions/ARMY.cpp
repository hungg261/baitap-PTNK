/******************************************************************************
Link: ARMY
Code: ARMY
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-03-10.16.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXM = 2e5;
int x, a[MAXN + 5];

vector<int> adj[MAXN + 5];
int n, m;

struct State{
    int node, remain;

    pair<int, int> get(){
        return make_pair(node, remain);
    }
};

int dp[MAXN + 5];
void solve(){
    queue<State> que;
    que.push({0, x});
    dp[0] = x;

    while(!que.empty()){
        State curState = que.front();
        int u, remain; tie(u, remain) = curState.get();
        que.pop();

        if(remain < dp[u]) continue;
        dp[u] = remain;

        for(int v: adj[u]){
            int newRemain = remain > a[v] ? remain : remain / 2;
            if(newRemain > dp[v]){
                que.push({v, newRemain});
            }
        }
    }

    cout << dp[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ARMY.INP","r",stdin);
    freopen("ARMY.OUT","w",stdout);
    cin >> n >> m;
    adj[0].push_back(1);
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    solve();

    return 0;
}
