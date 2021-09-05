#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
ll comb(ll a, ll b) {
    return a + b;
}
 
ll e() {
    return 0LL;
}
 
template<class T, T (*comb)(T, T), T (*e)()> struct SegTree {
    vector<T> t;
    int size;
 
    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
 
    void build(vector<T> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                t[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)>>1;
        build(a, (x<<1) + 1, lx, m);
        build(a, (x<<1) + 2, m, rx);
        t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
    }
 
    void set(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx)>>1;
        if (i < m) {
            set(i, v, (x<<1) + 1, lx, m);
        }
        else {
            set(i, v, (x<<1) + 2, m, rx);
        }
        t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
    }
 
    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return e();
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)>>1;
        T sl = query(l, r, (x<<1) + 1, lx, m);
        T sr = query(l, r, (x<<1) + 2, m, rx);
        return comb(sl, sr);
    }
 
    void build(vector<T> &a, int n) {
        size = 1;
        while (size < n) size<<= 1;
        t.assign((size<<1), e());
        build(a, 0, 0, size);
    }
    
    void set(int i, T v) {
        set(i, v, 0, 0, size);
    }
 
    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n;
    vector<ll> a(n), b(n);
    SegTree<ll, comb, e> stodd, steven;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cin >> b[i];
        else cin >> a[i];
    }
    steven.build(b, (int) a.size());
    stodd.build(a, (int) b.size());
    cin >> m;
    while (m--) {
        int id; cin >> id;
        if (id == 0) {
            int i, j; cin >> i >> j; i--;
            if (i % 2 == 0) steven.set(i, j);
            else stodd.set(i, j);
        }
        else {
            int l, r; cin >> l >> r; l--; r--;
            // cout << steven.query(l, r + 1) << ' ' << stodd.query(l, r + 1) << ' ';
            if (l % 2 == 0) cout << steven.query(l, r + 1) - stodd.query(l, r + 1) << '\n';
            else cout << stodd.query(l, r + 1) - steven.query(l, r + 1) << '\n';
        }
    }
    return 0;
}