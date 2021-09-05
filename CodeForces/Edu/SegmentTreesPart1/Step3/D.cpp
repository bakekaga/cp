#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
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
 
int seen[MAXN];
int sum[MAXN];
 
void solve(int n, vector<int> &a, vector<int> &b) {
    SegTree<int, comb, e> st;
    st.build(b, n);
    fill(seen, seen + n/2, -1);
 
    for (int i = 0; i < n; i++) {
        if (seen[a[i]] == -1) {
            seen[a[i]] = i;
            st.set(i, 1);
        }
        else {
            st.set(seen[a[i]], 0);
            sum[a[i]]+= st.query(seen[a[i]], i + 1);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; n*= 2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    
    solve(n, a, b);
    reverse(a.begin(), a.end());
    solve(n, a, b);
 
    for (int i = 0; i < n / 2; i++) {
        cout << sum[i] << ' ';
    }
    return 0;
}