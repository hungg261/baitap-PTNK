/******************************************************************************
Link: SROBOT
Code: SROBOT
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-11-14.38.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void convert(char cmd, int& x, int& y){
    if(cmd == 'U') y += 1;
    else if(cmd == 'D') y -= 1;
    else if(cmd == 'L') x -= 1;
    else if(cmd == 'R') x += 1;
}

void moveBy(const string& path, int& x, int& y){
    for(char cmd: path){
        convert(cmd, x, y);
    }
}

bool onPath(const string& path, int x, int y, int xTarget, int yTarget){
    if(x == xTarget && y == yTarget) return true;
    for(char cmd: path){
        convert(cmd, x, y);
        if(x == xTarget && y == yTarget) return true;
    }

    return false;
}

void solve(){
    int xTarget, yTarget;
    string path;

    cin >> xTarget >> yTarget >> path;

    int x = 0, y = 0;
    int xEnd = x, yEnd = y;
    moveBy(path, xEnd, yEnd);

    cerr << xEnd << ' ' << yEnd << '\n';

    int deltaX = xEnd - x, deltaY = yEnd - y;
    for(char cmd: path){
        convert(cmd, x, y);
        convert(cmd, xEnd, yEnd);

        if(xTarget * deltaY == yTarget * deltaX){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("SROBOT.INP","r",stdin);
    //freopen("SROBOT.OUT","w",stdout);

    solve();

    return 0;
}
