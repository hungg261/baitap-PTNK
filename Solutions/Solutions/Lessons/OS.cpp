/******************************************************************************
Link: OS
Code: OS
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-13-13.24.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXM = 2e5; // 2 * n gia tri phan biet
vector<int> values;
int m, n;
vector<pair<int, int>> queries;

int nodes[MAXM * 4 + 5], lazy[MAXM * 4 + 5];

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

void solve(){
    reverse(begin(queries), end(queries));
    int ans = 0;
    for(const pair<int, int> qr: queries){
        int l, r;
        tie(l, r) = qr;

        if(get(1, 1, MAXM, l, r) == 0) ++ans;
        update(1, 1, MAXM, l, r, 1);
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("OS.INP","r",stdin);
    freopen("OS.OUT","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= n; ++i){
        int l, r;
        cin >> l >> r;

        values.push_back(l);
        values.push_back(r);
        queries.emplace_back(l, r);
    }

    sort(begin(values), end(values));
    values.erase(unique(begin(values), end(values)), end(values));

    auto compress = [&](int& x){
        x = lower_bound(begin(values), end(values), x) - begin(values) + 1;
    };

    for(pair<int, int>& qr: queries){
        compress(qr.first);
        compress(qr.second);
    }

    solve();

    return 0;
}
