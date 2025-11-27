/******************************************************************************
Link: CIRCLE
Code: CIRCLE
Time (YYYY-MM-DD-hh.mm.ss): 2025-10-06-10.03.01
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5000;
struct Point{
    int x, y, w;

    Point(int _x, int _y, int _w): x(_x), y(_y), w(_w){}

    int pow2_dist(const Point& other){
        return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y);
    }
};
vector<Point> points;
int n;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CIRCLE.INP","r",stdin);
    freopen("CIRCLE.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;

        points.push_back(Point(x, y, 1));
    }
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;

        points.push_back(Point(x, y, -1));
    }

    Point origin(0, 0, 0);

    int ans = 1e18;
    int sz = points.size();
    for(int i = 0; i < sz; ++i){
        int dist = origin.pow2_dist(points[i]);

        int delta = 0;
        for(int j = 0; j < sz; ++j){
            if(origin.pow2_dist(points[j]) <= dist){
                delta += points[j].w;
            }
        }

        if(delta == 0){
            ans = min(ans, dist);
        }
    }

    cout << fixed << setprecision(6) << sqrt(ans) << '\n';

    return 0;
}
