/******************************************************************************
Link: ELEVATOR
Code: ELEVATOR
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-04-14.21.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int n, k, m, t;
int arr[MAXN + 5];

bool check(int mid){


    return total >= mid;
}

void solve(){
    int l = 1, r = 1e9, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("ELEVATOR.INP","r",stdin);
    //freopen("ELEVATOR.OUT","w",stdout);
    cin >> n >> k >> m >> t;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    return 0;
}
