#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

template <class S = int> struct segtree {
  public:
    S op(S a, S b) {
        return a + b;
    }

    S e() {
        return 0;
    }

    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(_n)) log++;
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
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
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

void solve() {
	int n, m, sum = 0; cin >> n >> m;
	vector<int> v(n * m), a(n * m);
    map<int, int> used;
    map<int, vector<pair<int, int>>> loc;
    segtree<> st(v);
    for (int i = 0; i < n * m; i++) {
        cin >> v[i];
        a[i] = v[i];
    }
    sort(v.begin(), v.end());
    for (int i : v) {
        if (!loc.count(i)) {
            int lo = lower_bound(v.begin(), v.end(), i) - v.begin();
            int hi = upper_bound(v.begin(), v.end(), i) - v.begin();
            for (int j = lo; j < hi; j++) {
                loc[i].pb(mp(j / m, -(j % m)));
            }
            sort(loc[i].begin(), loc[i].end());
        }
    }

    for (int i : a) {
        int row = loc[i][used[i]].first * m;
        int col = loc[i][used[i]].second;
        sum+= st.prod(row, row - col);
        st.set(row - col, 1);
        used[i]++;
    }
	cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}