/******************************************************************************
Link: https://ptnkoj.com/problem/tphai_nhapmon03
Code: tphai_nhapmon03
Time (YYYY-MM-DD-hh.mm.ss): 2025-11-27-18.34.45
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

namespace Geometry{

const double EPS = 1e-9;
int sgn(double x){ return (x > EPS) - (x < -EPS); }

/* ==================== POINT / VECTOR ==================== */
struct Point{
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}

    Point operator + (const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator - (const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator * (double k) const { return Point(x * k, y * k); }
    Point operator / (double k) const { return Point(x / k, y / k); }

    bool operator == (const Point &o) const { return sgn(x - o.x) == 0 && sgn(y - o.y) == 0; }
    bool operator < (const Point &o) const {
        return x < o.x - EPS || (sgn(x - o.x) == 0 && y < o.y - EPS);
    }
};

/* ===== INPUT/OUTPUT for Point ===== */
istream& operator>>(istream &in, Point &p){
    return in >> p.x >> p.y;
}
ostream& operator<<(ostream &out, const Point &p){
    return out << p.x << " " << p.y;
}

/* vector utilities */
double dot(const Point& a, const Point& b){ return a.x * b.x + a.y * b.y; }
double cross(const Point& a, const Point& b){ return a.x * b.y - a.y * b.x; }
double norm2(const Point& a){ return dot(a, a); }
double norm(const Point& a){ return sqrt(dot(a,a)); }
Point unit(const Point& a){ return a / norm(a); }

Point rotateCCW(const Point& a, double ang){
    double c = cos(ang), s = sin(ang);
    return Point(a.x * c - a.y * s, a.x * s + a.y * c);
}

/* ==================== ORIENTATION (CCW) ==================== */
int ccw(const Point& A, const Point& B, const Point& C){
    return sgn(cross(B - A, C - A));
}

/* ==================== LINE / SEGMENT ==================== */
struct Line{
    Point a, b;
    Line() {}
    Line(Point _a, Point _b): a(_a), b(_b) {}
};

/* ===== INPUT/OUTPUT for Line ===== */
istream& operator>>(istream &in, Line &L){
    return in >> L.a >> L.b;
}
ostream& operator<<(ostream &out, const Line &L){
    return out << L.a << " " << L.b;
}

bool onSegment(Point A, Point B, Point P){
    if(ccw(A,B,P) != 0) return false;
    return sgn(dot(P-A, P-B)) <= 0;
}

/* ==================== DISTANCES ==================== */
double dist(Point a, Point b){
    return norm(a - b);
}

double distPointLine(Point P, Line L){
    Point A = L.a, B = L.b;
    return fabs(cross(B - A, P - A)) / dist(A, B);
}

double distPointSegment(Point P, Point A, Point B){
    Point AB = B - A, AP = P - A, BP = P - B;
    if(sgn(dot(AP, AB)) < 0) return norm(AP);
    if(sgn(dot(BP, AB)) > 0) return norm(BP);
    return fabs(cross(AB, AP)) / norm(AB);
}

/* ==================== PROJECTION / REFLECTION ==================== */
Point projectPointLine(Point P, Line L){
    Point A = L.a, B = L.b;
    Point AB = B - A;
    double t = dot(P - A, AB) / dot(AB, AB);
    return A + AB * t;
}

Point reflectPointLine(Point P, Line L){
    return projectPointLine(P, L) * 2 - P;
}

/* ==================== LINE INTERSECTION ==================== */
bool intersectLine(Line L1, Line L2, Point &out){
    Point A = L1.a, B = L1.b, C = L2.a, D = L2.b;
    Point AB = B - A, CD = D - C;
    double denom = cross(AB, CD);
    if(sgn(denom) == 0) return false;

    double t = cross(C - A, CD) / denom;
    out = A + AB * t;
    return true;
}

bool intersectSegment(Point A, Point B, Point C, Point D, Point &out){
    Line L1(A, B), L2(C, D);
    if(!intersectLine(L1, L2, out)) return false;
    return onSegment(A, B, out) && onSegment(C, D, out);
}

/* ==================== POLYGON ==================== */
double polygonArea(const vector<Point>& P){
    double S = 0;
    int n = P.size();
    for(int i = 0; i < n; i++)
        S += cross(P[i], P[(i+1)%n]);
    return fabs(S) / 2;
}

/* Convex Hull – Andrew O(n log n) */
vector<Point> convexHull(vector<Point> P){
    int n = P.size();
    if(n <= 1) return P;

    sort(P.begin(), P.end());
    vector<Point> L, U;

    for (auto &p : P){
        while(L.size() >= 2 && ccw(L[L.size()-2], L.back(), p) <= 0)
            L.pop_back();
        L.push_back(p);
    }
    for (int i = n-1; i >= 0; i--){
        auto p = P[i];
        while(U.size() >= 2 && ccw(U[U.size()-2], U.back(), p) <= 0)
            U.pop_back();
        U.push_back(p);
    }

    L.pop_back();
    U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

}

using namespace Geometry;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    Point A, B, C;
    cin >> A >> B >> C;

    Point mAB = (A + B) / 2, mBC = (B + C) / 2;
    cout << mAB << '\n';
    cout << mBC << '\n';

    return 0;
}
