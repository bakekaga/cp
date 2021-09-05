#include <bits/stdc++.h>
#define MAXN 50005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
template<class T> struct SegTree {
    vector<T> t;
    int size;
    const T initial = mp(INT_MAX, 0);
 
    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
 
    T comb(T a, T b) {
        if (a.first < b.first) return mp(a.first, a.second);
        if (a.first > b.first) return mp(b.first, b.second);
        return mp(a.first, a.second + b.second);
    }
 
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
        if (lx >= r || l >= rx) return initial;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)>>1;
        T sl = query(l, r, (x<<1) + 1, lx, m);
        T sr = query(l, r, (x<<1) + 2, m, rx);
        return comb(sl, sr);
    }
 
    void build(vector<T> &a, int n) {
        size = 1;
        while (size < n) size <<= 1;
        t.assign((size<<1), initial);
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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = 1;
    }
    SegTree<pair<int, int>> st;
    st.build(a, n);
 
    while(m--) {
        int id; cin >> id;
        if (id == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, mp(v, 1));
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r).first << " " << st.query(l, r).second << '\n';
        }
    } 
    return 0;
}