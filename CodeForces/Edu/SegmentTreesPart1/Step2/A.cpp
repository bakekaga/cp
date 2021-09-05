#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;
 
struct Node {
    ll pre, suf, sum, seg;
    Node() : Node(INT_MIN) {}
    Node(const ll &a) {
        pre = a; suf = a; sum = a; seg = a;
    }
};
 
template<class T> struct SegTree {
    vector<T> t;
    int size;
    const T initial;
 
    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
 
    T comb(T a, T b) {
        Node x;
        x.pre = max(a.pre, b.pre + a.sum);
        x.suf = max(a.suf + b.sum, b.suf);
        x.sum = a.sum + b.sum;
        x.seg = max(a.seg, max(b.seg, a.suf + b.pre));
        return x;
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
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        Node N = Node(x);
        a[i] = N;
    }
    SegTree<Node> st;
    st.build(a, n);
 
    cout << max(0LL, st.query(0, n).seg) << '\n';
    while(m--) {
        int i; ll v;
        cin >> i >> v;
        st.set(i, Node(v));
        cout << max(0LL, st.query(0, n).seg) << '\n';
    } 
    return 0;
}