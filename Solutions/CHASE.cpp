/******************************************************************************
Link: CHASE
Code: CHASE
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-17-10.13.47
*******************************************************************************/

// FIXME (CHASE): unfinished

#include<bits/stdc++.h>
using namespace std;

struct Oil{
    int x, a;
};

struct Fraction{
    int a, b;

    Fraction() = default;
    Fraction(int _a, int _b): a(_a), b(_b){ this->simplify(); }

    void simplify(){
        int g = __gcd(a, b);
        a /= g;
        b /= g;
    }

    Fraction operator * (const int& k) const{
        Fraction res(a * k, b);
        return res;
    }

    bool operator < (const Fraction& other){
        return this->a * other.b < other.a * this->b;
    }
};

const int MAXN = 1e5;
int n, k;
int v1, v2;
int s;
Oil oils[MAXN + 5];

bool mark[MAXN + 5];
void solve(){
    double police = 0, criminal = s;
    for(int i = 1; i <= n; ++i){
        double dist = oils[i].x - police;
        double t = dist / v2;

        police = oils[i].x;
        double newCriminal = criminal + v1 * t;

//        lower_bound()
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("CHASE.INP","r",stdin);
    //freopen("CHASE.OUT","w",stdout);
    cin >> n >> k;
    cin >> v1 >> v2;
    cin >> s;

    solve();

    return 0;
}

/*
6 2
1 2
3
0 1
5 2
7 3
10 4
11 5
12 6
*/
