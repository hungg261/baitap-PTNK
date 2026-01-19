/******************************************************************************
Link: CORRECTION
Code: CORRECTION
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-19-09.54.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz, high;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1, -1);
    }

    bool existed(int v){
        return par[v] != -1;
    }

    void init(){
        for(int v = 0; v <= n; ++v){
            create(v);
        }
    }

    void create(int v){
        par[v] = v;
    }

    int find_set(int v){
        return par[v] == v ? v : par[v] = find_set(par[v]);
    }

    bool union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            par[b] = a;
            return true;
        }

        return false;
    }
};

const int MAXN = 1e6, MAXVAL = 3e6;
int n, arr[MAXN + 5];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CORRECTION.INP","r",stdin);
    freopen("CORRECTION.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    DSU dsu(MAXVAL + 5);
    dsu.init();

    for(int i = 1; i <= n; ++i){
        int cur = dsu.find_set(arr[i]);
        cout << cur << ' ';

        dsu.union_sets(cur + 1, arr[i]);
    }

    return 0;
}
