/******************************************************************************
Link: EQUALTRIPLE
Code: EQUALTRIPLE
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-08-09.46.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int arr[3];
    for(int i = 0; i < 3; ++i) cin >> arr[i];

    sort(arr, arr + 3);

    int ans = arr[1] + arr[2] - 2 * arr[0];
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("EQUALTRIPLE.INP","r",stdin);
    freopen("EQUALTRIPLE.OUT","w",stdout);

    solve();

    return 0;
}
