/******************************************************************************
Link: EBOLA
Code: EBOLA
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-03-10.51.00
*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
int n, k;
const int maxn = 1e5;
vector < int > adj[maxn + 7];
bool visited[maxn + 7];
void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int a;
            cin >> a;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
    }
}
void solve() {
    queue < int > q;
    q.push(k);
    int res = 1;
    visited[k] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i: adj[u]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push(i);
                res++;
            }
        }
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cout << i << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("EBOLA.INP", "r", stdin);
    freopen("EBOLA.OUT", "w", stdout);
    input();
    solve();
    return 0;
}
