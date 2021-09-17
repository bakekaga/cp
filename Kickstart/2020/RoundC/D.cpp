#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
pair<ll, ll> comb(pair<ll, ll> a, pair<ll, ll> b) {
    return mp(a.first + b.first, a.second + b.second);
}

pair<ll, ll> e() {
    return mp(0LL, 0LL);
}

template<class T, T (*comb)(T, T), T (*e)()> struct SegTree {
    vector<T> t;
    int size;
 
    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
 
    void build(vector<ll> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                if (lx % 2 != 0) {
                    t[x].first = a[lx];
                    t[x].second = a[lx] * lx;
                }
                else {
                    t[x].first = -a[lx];
                    t[x].second = -a[lx] * lx;
                }
            }
            return;
        }
        int m = (lx + rx)>>1;
        build(a, (x<<1) + 1, lx, m);
        build(a, (x<<1) + 2, m, rx);
        t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
    }
 
    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx % 2 != 0) {
                t[x].first = v;
                t[x].second = v * i;
            }
            else {
                t[x].first = -v;
                t[x].second = -v * i;
            }
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
 
    void build(vector<ll> &a, int n) {
        size = 1;
        while (size < n) size<<= 1;
        t.assign((size<<1), e());
        build(a, 0, 0, size);
    }
    
    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }
 
    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, q; cin >> n >> q; n++;
        vector<ll> a(n);
        SegTree<pair<ll, ll>, comb, e> st;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        st.build(a, n);
        
        ll sum = 0;
        while (q--) {
            char id; cin >> id;
            if (id == 'U') {
                int x, v; cin >> x >> v;
                st.set(x, v);
                st.set(x, v);
            }
            else {
                int l, r; cin >> l >> r;
                ll val = st.query(l, r + 1).second - (l - 1) * st.query(l, r + 1).first;
                if (l % 2 != 0)
                    sum+= val;
                else
                    sum+= -val;
            }
        }
        cout << "Case #" << tt << ": " << sum << '\n';
    }
    return 0;
}