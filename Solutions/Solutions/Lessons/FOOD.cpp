/******************************************************************************
Link: FOOD
Code: FOOD
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-17-10.45.17
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
int m, k, c[MAXN + 5];

int dp[MAXN + 5];
int buy[MAXN + 5];
void solve(){
    deque<int> dq;
    for(int i = 1; i <= m; ++i){
        if(!dq.empty() && i - dq.back() + 1 > k) dq.pop_back();
        while(!dq.empty() && c[dq.front()] > c[i]) dq.pop_front();
        dq.push_front(i);

        buy[dq.back()] += 2;
        dp[i] = dp[i - 1] + c[dq.back()] * 2;
    }

    cout << dp[m] << '\n';
    for(int i = 1; i <= m; ++i) cout << buy[i] << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FOOD.INP","r",stdin);
    freopen("FOOD.OUT","w",stdout);
    cin >> m >> k;
    for(int i = 1; i <= m; ++i){
        cin >> c[i];
    }

    solve();

    return 0;
}

/*
10 3
1 7 4 2 5 1 5 2 3 7


6 6
1 1 2 3 4 5
*/
