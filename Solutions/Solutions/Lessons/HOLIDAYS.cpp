/******************************************************************************
Link: HOLIDAYS
Code: HOLIDAYS
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-08-09.18.50
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Cake{
    int a, b;
    int idx;

    struct cmpSad{
        bool operator () (const Cake &X, const Cake &Y) const{
            if(X.a == Y.a){
                if(X.b == Y.b) return X.idx < Y.idx;
                return X.b < Y.b;
            }
            return X.a < Y.a;
        }
    };

    struct cmpHappy{
        bool operator () (const Cake &X, const Cake &Y) const{
            if(X.b == Y.b){
                if(X.a == Y.a) return X.idx < Y.idx;
                return X.a < Y.a;
            }
            return X.b < Y.b;
        }
    };
};

const int MAXN = 1e5;
int n;
Cake cakes[MAXN + 5];
bool eaten[MAXN + 5];

bool cmpSad(int a, int b){
    const Cake& X = cakes[a];
    const Cake& Y = cakes[b];

    if(X.a == Y.a){
        if(X.b == Y.b) return X.idx < Y.idx;
        return X.b > Y.b;
    }
    return X.a > Y.a;
}

bool cmpHappy(int a, int b){
    const Cake &X = cakes[a];
    const Cake &Y = cakes[b];

    if(X.b == Y.b){
        if(X.a == Y.a) return X.idx < Y.idx;
        return X.a > Y.a;
    }
    return X.b > Y.b;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("HOLIDAYS.INP","r",stdin);
    freopen("HOLIDAYS.OUT","w",stdout);

    cin >> n;
    vector<int> HappyQueue(n);
    vector<int> SadQueue(n);
    for(int i = 1; i <= n; ++i) cin >> cakes[i].a;
    for(int i = 1; i <= n; ++i) cin >> cakes[i].b;

    iota(HappyQueue.begin(), HappyQueue.end(), 1);
    sort(HappyQueue.begin(), HappyQueue.end(), cmpHappy);

    iota(SadQueue.begin(), SadQueue.end(), 1);
    sort(SadQueue.begin(), SadQueue.end(), cmpSad);

    int happyIdx = 0, sadIdx = 0;
    for(int i = 1; i <= n; ++i){
        int mood; cin >> mood;

        int idx;
        if(mood){
            do{
                idx = HappyQueue[happyIdx++];
            } while(happyIdx < n && eaten[idx]);

            eaten[idx] = true;
        }
        else{
            do{
                idx = SadQueue[sadIdx++];
            } while(sadIdx < n && eaten[idx]);

            eaten[idx] = true;
        }

        cout << idx << ' ';
    }

    return 0;
}
