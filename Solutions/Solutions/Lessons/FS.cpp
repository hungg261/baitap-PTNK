/******************************************************************************
Link: FS
Code: FS
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-04-13.11.28
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int is_squared(int n){
    int sq = sqrt(n);
    if(sq * sq == n) return sq;
    if((sq + 1) * (sq + 1) == n) return sq + 1;
    if((sq - 1) * (sq - 1) == n) return sq - 1;

    return -36;
}

void sussybaka(int& x, int& y, int bx, int by, int shiftx, int shifty){
    x = bx + shiftx;
    y = by + shifty;
}

void construct(int a, int b){
    int x1, y1,
        x2, y2,
        x3, y3,
        x4, y4;

    x1 = y1 = 0;
    sussybaka(x2, y2, x1, y1, a, b);
    sussybaka(x3, y3, x1, y1, -b, a);
    sussybaka(x4, y4, x3, y3, a, b);

    cout << x1 << ' ' << y1 << '\n';
    cout << x2 << ' ' << y2 << '\n';
    cout << x3 << ' ' << y3 << '\n';
    cout << x4 << ' ' << y4 << '\n';

}

void solve(int S){
    for(int a = 0; a * a <= S; ++a){
        int b = is_squared(S - a * a);

        if(b != -36){
            construct(a, b);
            return;
        }
    }

    cout << "Impossible\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FS.INP","r",stdin);
    freopen("FS.OUT","w",stdout);
    int S;
    cin >> S;

    solve(S);

    return 0;
}
