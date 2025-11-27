/******************************************************************************
Link: POPUST
Code: POPUST
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-11-15.35.59
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5e5;
int n;
pair<int, int> tables[MAXN + 5];

int preMaxB[MAXN + 5], sufMinA[MAXN + 5], preMaxDiff[MAXN + 5];
void compute(){
    preMaxB[0] = -1e18;
    preMaxDiff[0] = -1e18;
    for(int i = 1; i <= n; ++i){
        preMaxB[i] = max(preMaxB[i - 1], tables[i].second);
        preMaxDiff[i] = max(preMaxDiff[i - 1], tables[i].second - tables[i].first);
    }

    sufMinA[n + 1] = 1e18;
    for(int i = n; i >= 1; --i){
        sufMinA[i] = min(sufMinA[i + 1], tables[i].first);
    }
}

void solve(){
    int prefix = 0;
    for(int i = 1; i <= n; ++i){
        prefix += tables[i].second;

        int ans = prefix - max(preMaxDiff[i], preMaxB[i] - sufMinA[i + 1]);
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("POPUST.INP","r",stdin);
    freopen("POPUST.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> tables[i].first >> tables[i].second;
    }

    sort(tables + 1, tables + n + 1, [](auto& x, auto& y){
            return x.second < y.second;
         });
    compute();
    solve();

    return 0;
}
