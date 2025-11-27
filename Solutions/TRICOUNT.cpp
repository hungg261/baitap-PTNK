/******************************************************************************
Link: TRICOUNT
Code: TRICOUNT
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-06-09.46.18
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 300000;
struct Point{
    int x, y;
} points[MAXN + 5];
int n;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TRICOUNT.INP","r",stdin);
    freopen("TRICOUNT.OUT","w",stdout);
    cin >> n;
    map<int, vector<Point>> mp_x;
    map<int, int> mp_y;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;

        points[i] = {x, y};
        mp_x[x].push_back(points[i]);
        mp_y[y]++;
    }

    int ans = 0;
    for(const auto& p: mp_x){
        int x = p.first;
        const auto& vec = p.second;

        int sz_x = vec.size();
        for(int i = 0; i < sz_x; ++i){
            ans += (mp_y[vec[i].y] - 1) * (sz_x - 1);
        }
    }

    cout << ans << '\n';

    return 0;
}
