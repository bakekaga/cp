#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

double x;

struct Point { ll x, y; int segind; };

bool operator<(Point p, Point q) { return p.x == q.x ? p.y < q.y : p.x < q.x; };

struct Segment {
    Point p, q; int ind;
    double get_y(double x) {
        return p.x == q.x ? p.y : p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

int sign(ll x) { if (x == 0) return 0; else return x < 0 ? -1 : 1; }
int operator*(Point p1, Point p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
Point operator-(Point p1, Point p2) { Point p = {p1.x - p2.x, p1.y - p2.y}; return p; }
bool intersect(Segment &s1, Segment &s2)
{
    Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
    return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}

bool operator==(Segment seg1, Segment seg2) { return seg1.ind == seg2.ind; }
bool operator<(Segment seg1, Segment seg2) {
    return seg1.ind != seg2.ind && seg1.get_y(x) < seg2.get_y(x);
}

int main() {
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    
    int n; cin >> n;
    vector<Segment> segs;
    vector<Point> events;
    for (int i = 0; i < n; i++) {
        Segment s;
        cin >> s.p.x >> s.p.y >> s.q.x >> s.q.y;
        s.ind = s.p.segind = s.q.segind = i;
        events.pb(s.p);
        events.pb(s.q);
        segs.pb(s);
    }
    sort(events.begin(), events.end());
        
    set<Segment> cur;
    int ans1, ans2;
    for (int i = 0; i < 2 * n; i++) {
        ans1 = events[i].segind; x = events[i].x;
        auto it = cur.find(segs[ans1]);
        if (it != cur.end()) {
            auto after = it, before = it; after++;
            if (before != cur.begin() && after != cur.end()) {
                before--;
                if (intersect(segs[before->ind], segs[after->ind])) {
                    ans1 = before->ind;
                    ans2 = after->ind;
                    break;
                }
            }
            cur.erase(it);
        }
        else {
            auto it = cur.lower_bound(segs[ans1]);
            if (it != cur.end() && intersect(segs[it->ind], segs[ans1])) {
                ans2 = it->ind;
                break;
            }
            if (it != cur.begin()) {
                it--;
                if (intersect(segs[it->ind], segs[ans1])) {
                    ans2 = it->ind;
                    break;
                }
            }
            cur.insert(segs[ans1]);
        }
    }

    if (ans1 > ans2) swap(ans1, ans2);
    int seg2cnt = 0;
    for (int i = 0; i < n; i++) {
        if (segs[i].ind != ans2 && intersect(segs[ans2], segs[i])) {
            seg2cnt++;
        }
    }
    if (seg2cnt > 1) cout << ans2 + 1 << '\n';
    else cout << ans1 + 1 << '\n';

    return 0;
}