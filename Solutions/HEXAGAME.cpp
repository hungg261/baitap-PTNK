/******************************************************************************
Link: HEXAGAME
Code: HEXAGAME
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-10-09.30.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct State{
    vector<vector<int>> arr;
    int mov = 0;

    State(){
        arr.resize(3);
        arr[0].resize(3);
        arr[1].resize(4);
        arr[2].resize(3);
    }

    long long id(){
        long long mask = 0;
        for(int i = 0; i < 3; ++i) mask = mask * 10 + arr[0][i];
        for(int i = 0; i < 4; ++i) mask = mask * 10 + arr[1][i];
        for(int i = 0; i < 3; ++i) mask = mask * 10 + arr[2][i];

        return mask;
    }

    static State Identity(){
        State res;
        res.arr[0][0] = 1;
        res.arr[0][1] = 2;
        res.arr[0][2] = 3;

        res.arr[1][0] = 8;
        res.arr[1][1] = 0;
        res.arr[1][2] = 0;
        res.arr[1][3] = 4;

        res.arr[2][0] = 7;
        res.arr[2][1] = 6;
        res.arr[2][2] = 5;

        return res;
    }

    bool Compare(const State& target){
        for(int i = 0; i < 3; ++i) if(arr[0][i] != target.arr[0][i]) return false;
        for(int i = 0; i < 4; ++i) if(arr[1][i] != target.arr[1][i]) return false;
        for(int i = 0; i < 3; ++i) if(arr[2][i] != target.arr[2][i]) return false;
        return true;
    }

    void rotate(bool type, bool __increment = true){
        int root = arr[0][type + 0];
        arr[0][type + 0] = arr[1][type + 0];
        arr[1][type + 0] = arr[2][type + 0];
        arr[2][type + 0] = arr[2][type + 1];
        arr[2][type + 1] = arr[1][type + 2];
        arr[1][type + 2] = arr[0][type + 1];
        arr[0][type + 1] = root;

        if(__increment) ++this->mov;
    }

    void input(){
        for(int i = 0; i < 3; ++i) cin >> arr[0][i];
        for(int i = 0; i < 4; ++i) cin >> arr[1][i];
        for(int i = 0; i < 3; ++i) cin >> arr[2][i];
    }
};

State TARGET = State::Identity();
State origin;
void bfs(){
    if(origin.Compare(TARGET)){
        cout << "0\n";
        return;
    }

    queue<State> que;
    unordered_set<long long> mark;

    que.push(origin);
    mark.insert(origin.id());
    while(!que.empty()){
        State cur = que.front();
        que.pop();

        State nxt = cur;
        cur.rotate(0);
        nxt.rotate(1);

        if(cur.Compare(TARGET) || nxt.Compare(TARGET)){
            cout << cur.mov << '\n';
            return;
        }

        if(!mark.count(cur.id())) que.push(cur);
        if(!mark.count(nxt.id())) que.push(nxt);

    }

    cout << "-1\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("HEXAGAME.INP","r",stdin);
//    freopen("HEXAGAME.OUT","w",stdout);

    origin.input();
    bfs();

    return 0;
}

/*
SAMPLE:

1 0 2
8 6 0 3
7 5 4
-> 5

1 6 0
8 5 0 2
7 4 3
-> 4

1 7 2
6 5 0 4
8 3 0
-> 21


*/
