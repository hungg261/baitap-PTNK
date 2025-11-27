/******************************************************************************
Link: COMPUTING
Code: COMPUTING
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-06-10.41.43
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COMPUTING.INP","r",stdin);
    freopen("COMPUTING.OUT","w",stdout);

    int n, k;
    cin >> n >> k;

    vector<int> pre(n + 1);
    for(int i = 1; i <= n; ++i){
        int cur; cin >> cur;
        pre[i] = pre[i - 1] + cur;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int l = max(1LL, i - k), r = min(n, i + k);
        ans = max(ans, (pre[n] - (pre[r] - pre[l - 1])) + (pre[i] - pre[i - 1]) * (r - l + 1));
    }

    cout << ans << '\n';

    return 0;
}
