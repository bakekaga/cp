// SEGMENT TREE
#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

template<class T> bool ckmin(T &a, const T &b) { return b<a?a=b,1:0; }
template<class T> bool ckmax(T &a, const T &b) { return b>a?a=b,1:0; }

template<class T = ll> struct SegTree {
    vector<T> t;
    int size, n;

    T comb(T a, T b) {
        return (a > b) ? gcd_impl(a, b) : gcd_impl(b, a);
    }

    T e() {
        return -1;
    }

    // constructors
    SegTree() : SegTree(0) {}
    explicit SegTree(int n) : SegTree(vector<T>(n, e())) {}
    explicit SegTree(const vector<T> &a) : n(int(a.size())) {
        size = 1;
        while (size < n) size<<= 1;
        t = vector<T>((size<<1), e());
        build(a, 0, 0, size);
    }

    // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
    void build(const vector<T> &a, int x, int lx, int rx) {
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
        if (i < m) set(i, v, (x<<1) + 1, lx, m);
        else set(i, v, (x<<1) + 2, m, rx);
        t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) const {
        if (lx >= r || l >= rx) return e();
        if (lx >= l && rx <= r) return t[x];
        int m = (lx + rx)>>1;
        T sl = query(l, r, (x<<1) + 1, lx, m);
        T sr = query(l, r, (x<<1) + 2, m, rx);
        return comb(sl, sr);
    }
    
    int first_above(int k, int x, int lx, int rx, int l) const {
        if (t[x] < k || rx <= l) return -1;
        if (rx == lx + 1) return x - size + 1;
        int m = (lx + rx)>>1;
        int res = first_above(k, (x<<1) + 1, lx, m, l);
        if (res == -1) res = first_above(k, (x<<1) + 2, m, rx, l);
        return res;
    }

    template<class F> int max_right(F f, int x, int lx, int rx, int l) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if (l == n) return n;

        if (f(t[x]) || rx <= l) return -1;
        if (rx == lx + 1) return x - size;
        int m = (lx + rx)>>1;
        int res = max_right(f, (x<<1) + 1, lx, m, l);
        if (res == -1) res = max_right(f, (x<<1) + 2, m, rx, l);
        return res;

        if (l == n) return n;
        l += size;
        T sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    void set(int i, T v) {
        set(i, v, 0, 0, size);
    }

    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return (l == r) ? e() : query(l, r, 0, 0, size);
    }

    template<bool (*f)(T)> int max_right(int l) const {
        return max_right([](T x) { return f(x); }, 0, 0, size, l);
    }

    // template<bool (*f)(T)> int min_left(int r) const {
    //     return min_left([](T x) { return f(x); }, 0, 0, size, r);
    // }
};
bool ok(ll x) {
    return x > 1LL;
}

int main() {
    vector<ll> a = {1, 2, 0, 1, 2};
    SegTree<ll> st(a);

    cout << st.max_right<ok>(3);
    return 0;
}