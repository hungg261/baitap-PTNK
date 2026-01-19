/******************************************************************************
Link: TICKET
Code: TICKET
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-13-13.52.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 5e5;
int nodes[MAXN * 4 + 5], lazy[MAXN * 4 + 5];

void push(int id, int l, int r){
    int &lz = lazy[id];
    int mid = (l + r) >> 1;

    nodes[id << 1] += lz * (mid - l + 1);
    lazy[id << 1] += lz;

    nodes[id << 1 | 1] += lz * (r - mid);
    lazy[id << 1 | 1] += lz;

    lz = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        nodes[id] = val * (r - l + 1);
        lazy[id] += val;
        return;
    }

    push(id, l, r);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return nodes[id];

    push(id, l, r);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("TICKET.INP","r",stdin);
    //freopen("TICKET.OUT","w",stdout);
    cin >> n >> k >> m;

    return 0;
}
