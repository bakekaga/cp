// POINT 
#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double eps = 1e-6;

template<typename T> struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x_, T y_) : x(x_), y(y_) {}
    Point(pair<T, T> p) : x(p.first), y(p.second) {}

	friend istream& operator>> (istream& i, Point& p) { return i >> p.x >> p.y; }
    friend bool operator== (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator!= (const Point& a, const Point& b) { return !(a==b); }

	Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
	Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
	Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
	Point& operator /= (const T& t) { x /= t, y /= t; return *this; }

	friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
	friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
	friend Point operator * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }
	friend Point operator * (const T& t, const Point& a) { return Point(t*a.x, t*a.y); }
	friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t); }

    T dist() const { return x * x + y * y; }
    auto arg() const { return atan2(y, x); }
    
	friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

	int sgn(const T& x) { return x >= 0 ? x ? 1 : 0 : -1; }

	bool inter1(T a, T b, T c, T d) {
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		return max(a, c) <= min(b, d);
	}

	bool check_inter(const Point& a, const Point& b, const Point& c, const Point& d) { // intersection of segments (a, b) with (c, d)
		if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
			return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
		return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
			sgn(c.cross(d, a)) != sgn(c.cross(d, b));
	}
};