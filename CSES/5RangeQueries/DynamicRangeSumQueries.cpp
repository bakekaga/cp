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
 
    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
 
    T comb(T a, T b) {
        return min(a, b);
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
        if (lx >= r || l >= rx) return INT_MAX;
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)>>1;
        T sl = query(l, r, (x<<1) + 1, lx, m);
        T sr = query(l, r, (x<<1) + 2, m, rx);
        return comb(sl, sr);
    }
 
    void build(vector<T> &a, int n) {
        size = 1;
        while (size < n) size *= 2;
        t.assign(2*size, INT_MAX);
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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegTree<ll> st;
    st.build(a, n);
 
    while(q--) {
        int id; cin >> id;
        if (id == 1) {
            int k; ll u;
            cin >> k >> u;
            st.set(k - 1, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << st.query(a - 1, b) << '\n';
        }
    } 
    return 0;
}