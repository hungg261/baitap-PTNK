#include <bits/stdc++.h>
using namespace std;

#define int long long
#define BIT(x, i) (((x) >> (i)) & 1)

const int MAXN = 1e5 + 5;
int n, a[MAXN];

int solve(vector<int> &val){
    vector<int> pref(n + 5, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = (pref[i - 1] + val[i]) & 1;
    vector<int> cnt ={0, 0};

    int res = 0;
    for (int i = 1; i <= n; ++i){
        cnt[pref[i - 1]]++;
        int contrib = cnt[pref[i] ^ 1];
        res += contrib;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("XORSUM.INP","r",stdin);
    freopen("XORSUM.OUT","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;
    for (int j = 0; j <= 21; ++j){
        vector<int> bit(n + 5, 0);
        for (int i = 1; i <= n; ++i) bit[i] = BIT(a[i], j);
        int mul = (1LL << j);
        res += mul * solve(bit);
    }

    cout << res;

    return 0;
}
