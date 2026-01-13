#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
int arr[MAXN + 5], n;

void solve(){
    int res = 0;
    for(int i = 0; i <= 31; ++i){
        int cnt = 0;
        for(int j = 1; j <= n; ++j){
            cnt += (arr[j] >> i&1);
        }
        res += cnt * (cnt - 1) / 2 * (1LL << i);
    }
    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    freopen("PANDS.INP","r",stdin);
    freopen("PANDS.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    solve();

    return 0;
}
