#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

int comb(int a, int b) {
    return a + b;
}
 
int e() {
    return 0;
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
            t[x] += v;
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
 
    int first_above(int k, int x, int lx, int rx, int l) {
        if (t[x] < k || rx <= l) return -1;
        if (rx == lx + 1) return x - size + 1;
        int m = (lx + rx)>>1;
        int res = first_above(k, (x<<1) + 1, lx, m, l);
        if (res == -1) res = first_above(k, (x<<1) + 2, m, rx, l);
        return res;
    }
 
    int first_above(int k, int l) {
        return first_above(k, 0, 0, size, l);
    }
};
 
ll inversions[MAXN];

int main() {
    setIO("haircut");

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegTree<int, comb, e> st;
    vector<int> b(n + 1, 0);
    st.build(b, n + 1);
 
    for (int i = 0; i < n; i++) {
        inversions[a[i]]+= st.query(a[i] + 1, n + 2);
        st.set(a[i], 1);
    }
    
    ll sum = 0; cout << sum << '\n';
    for (int i = 0; i < n - 1; i++) {
        sum+= inversions[i];
        cout << sum << '\n';
    }
    return 0;
}