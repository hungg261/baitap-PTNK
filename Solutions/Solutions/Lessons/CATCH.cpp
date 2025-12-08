/******************************************************************************
Link: CATCH
Code: CATCH
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-08-09.32.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
struct Point{
    int x, y;

    Point() = default;
    Point(int _x, int _y): x(_x), y(_y){}

    bool operator == (const Point& other) const{ return this->x == other.x && this->y == other.y; }
};

vector<Point> deadPoints;

void computeDeadPoints(int x, int y){
    deadPoints.emplace_back(x, y);
    for(int d = 0; d < 8; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        deadPoints.emplace_back(nx, ny);
    }
}

bool check(const Point& p){ return find(deadPoints.begin(), deadPoints.end(), p) != deadPoints.end(); }
bool check(int x, int y){ return check(Point(x, y)); }

pair<int, int> nxtPos(int x, int y, char instructor){
    if(instructor == 'L') return {x - 1, y};
    if(instructor == 'R') return {x + 1, y};
    if(instructor == 'U') return {x, y + 1};
    if(instructor == 'D') return {x, y - 1};
    throw runtime_error("skibidi");

    return {-1, -1};
}

void solve(const string& Path){
    int cx = 0, cy = 0;
    int sz = Path.size();

    bool caught = false;
    if(check(cx, cy)){
        cout << "0" << '\n';
        caught = true;
    }
    for(int id = 0; id < sz; ++id){
        tie(cx, cy) = nxtPos(cx, cy, Path[id]);

        if(check(cx, cy)){
            cout << id + 1 << '\n';
            caught = true;
        }
    }

    if(!caught){
        cout << "-1\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CATCH.INP","r",stdin);
    freopen("CATCH.OUT","w",stdout);
    int catx, caty;
    cin >> catx >> caty;

    computeDeadPoints(catx, caty);

    string Path;
    cin >> Path;

    solve(Path);

    return 0;
}
