// SEGMENT TREE
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

template <class S = int> struct segtree {
  public:
    S op(S a, S b) {
        return a + b;
    }

    S e() {
        return 0;
    }

    segtree() : segtree(0) {}
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(const vector<S>& v) : _n(sz(v)) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// template<class T = ll> struct SegTree {
//     vector<T> t;
//     int size, n;

//     T comb(T a, T b) {
//         return (a > b) ? gcd_impl(a, b) : gcd_impl(b, a);
//     }

//     T e() {
//         return -1;
//     }

//     // constructors
//     SegTree() : SegTree(0) {}
//     explicit SegTree(int n) : SegTree(vector<T>(n, e())) {}
//     explicit SegTree(const vector<T> &a) : n(int(a.size())) {
//         size = 1;
//         while (size < n) size<<= 1;
//         t = vector<T>((size<<1), e());
//         build(a, 0, 0, size);
//     }

//     // root is at index 0, left child of node x is 2*x+1, right child is 2*x+2
//     void build(const vector<T> &a, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             if (lx < (int)a.size()) {
//                 t[x] = a[lx];
//             }
//             return;
//         }
//         int m = (lx + rx)>>1;
//         build(a, (x<<1) + 1, lx, m);
//         build(a, (x<<1) + 2, m, rx);
//         t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
//     }

//     void set(int i, T v, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             t[x] = v;
//             return;
//         }
//         int m = (lx + rx)>>1;
//         if (i < m) set(i, v, (x<<1) + 1, lx, m);
//         else set(i, v, (x<<1) + 2, m, rx);
//         t[x] = comb(t[(x<<1) + 1], t[(x<<1) + 2]);
//     }

//     T query(int l, int r, int x, int lx, int rx) const {
//         if (lx >= r || l >= rx) return e();
//         if (lx >= l && rx <= r) return t[x];
//         int m = (lx + rx)>>1;
//         T sl = query(l, r, (x<<1) + 1, lx, m);
//         T sr = query(l, r, (x<<1) + 2, m, rx);
//         return comb(sl, sr);
//     }
    
//     int first_above(int k, int x, int lx, int rx, int l) const {
//         if (t[x] < k || rx <= l) return -1;
//         if (rx == lx + 1) return x - size + 1;
//         int m = (lx + rx)>>1;
//         int res = first_above(k, (x<<1) + 1, lx, m, l);
//         if (res == -1) res = first_above(k, (x<<1) + 2, m, rx, l);
//         return res;
//     }

//     template<class F> int max_right(F f, int x, int lx, int rx, int l) const {
//         assert(0 <= l && l <= n);
//         assert(f(e()));
//         if (l == n) return n;

//         if (f(t[x]) || rx <= l) return -1;
//         if (rx == lx + 1) return x - size;
//         int m = (lx + rx)>>1;
//         int res = max_right(f, (x<<1) + 1, lx, m, l);
//         if (res == -1) res = max_right(f, (x<<1) + 2, m, rx, l);
//         return res;

//         if (l == n) return n;
//         l += size;
//         T sm = e();
//         do {
//             while (l % 2 == 0) l >>= 1;
//             if (!f(op(sm, d[l]))) {
//                 while (l < size) {
//                     l = (2 * l);
//                     if (f(op(sm, d[l]))) {
//                         sm = op(sm, d[l]);
//                         l++;
//                     }
//                 }
//                 return l - size;
//             }
//             sm = op(sm, d[l]);
//             l++;
//         } while ((l & -l) != l);
//         return _n;
//     }

//     void set(int i, T v) {
//         set(i, v, 0, 0, size);
//     }

//     T query(int l, int r) const {
//         assert(0 <= l && l <= r && r <= n);
//         return (l == r) ? e() : query(l, r, 0, 0, size);
//     }

//     template<bool (*f)(T)> int max_right(int l) const {
//         return max_right([](T x) { return f(x); }, 0, 0, size, l);
//     }

//     // template<bool (*f)(T)> int min_left(int r) const {
//     //     return min_left([](T x) { return f(x); }, 0, 0, size, r);
//     // }
// };
