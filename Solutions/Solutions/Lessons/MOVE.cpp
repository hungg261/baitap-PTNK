/******************************************************************************
Link: MOVE
Code: MOVE
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-03-09.35.54
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int c[MAXN + 5];
vector<int> adj[MAXN + 5];
int n, A, B;

struct State{
    int node = -1;

    State(int _node): node(_node){}
};

bool bfs(int A, int B, int mid, bool output = false){
    queue<State> que;
    que.push({A});

    vector<bool> visited(n + 1, false);
    visited[A] = true;
    vector<int> par(n + 1, -1);
    while(!que.empty()){
        State curState = que.front();
        int u = curState.node;
        que.pop();

        if(u == B){
            if(output){
                vector<int> path;
                while(B != -1){
                    path.push_back(B);
                    B = par[B];
                }

                reverse(begin(path), end(path));
                for(int node: path) cout << node << ' ';
            }
            return true;
        }

        for(int v: adj[u]){
            if(!visited[v] && abs(c[u] - c[v]) <= mid){
                que.push({v});

                par[v] = u;

                visited[v] = true;
            }
        }
    }

    return false;
}

void solve(){
    int l = 1, r = 20000, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(bfs(A, B, mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if(res == -1){
        cout << "-1\n";
        return;
    }

    cout << res << '\n';
    bfs(A, B, res, true);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MOVE.INP","r",stdin);
    freopen("MOVE.OUT","w",stdout);
    cin >> n >> A >> B;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    int a, b;
    while(cin >> a >> b){
        if(a == -1) break;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve();

    return 0;
}
