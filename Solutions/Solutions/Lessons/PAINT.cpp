/******************************************************************************
Link: PAINT
Code: PAINT
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-02-15.02.06
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Depth(int x){
    int depth = 0;
    for(int bit = 0, cur = x; bit < 60; ++bit){
        if((1LL << bit) <= cur) cur -= 1LL << bit, ++depth;
    }
    return depth;
}

int find_par(int x){
    int depth = Depth(x);
    int first = (1LL << depth) - 1;
    int pos = x - first + 1;
    int half = 1LL << depth - 1;
    int prv_first = half - 1;

    if(x <= first + half - 1){
        if(pos & 1){
            return prv_first + (pos + 1) / 2 - 1;
        }
        else{
            return prv_first + half / 2 + pos / 2 - 1;
        }
    }
    else{
        pos -= half;
        if(pos & 1){
            return prv_first + (pos + 1) / 2 - 1;
        }
        else{
            return prv_first + half / 2 + pos / 2 - 1;
        }
    }
}

pair<int, int> find_children(int x){
    int depth = Depth(x);
    int first = (1LL << depth) - 1;
    int pos = x - first + 1;
    int half = 1LL << depth - 1;
    int nxt_first = (1LL << depth + 1) - 1;

    if(x <= first + half - 1){
        return {nxt_first + pos * 2 - 1 - 1, nxt_first + pos * 2 - 1 - 1 + (1LL << depth)};
    }
    else{
        pos -= half;
        return {nxt_first + pos * 2 - 1, nxt_first + pos * 2 - 1 + (1LL << depth)};
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    int n;
    cin >> n;

    int res1 = find_par(n);
    pair<int, int> res2 = find_children(n);
    cout << res1 << '\n';
    cout << res2.first << ' ' << res2.second << '\n';

    return 0;
}
