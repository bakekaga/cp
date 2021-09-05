#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
ll mod;
 
struct Mat {
    const static int n = 2;
    ll m[n][n];
    Mat() { memset(m, 0, sizeof m);}
 
    ll *operator[](const int &x) { return m[x]; }
    const ll *operator[](const int &x) const { return m[x]; }
 
    Mat operator*(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < n; a++) {
                    res[i][j] += m[i][a] * m2[a][j];
                    if (res[i][j] >= mod) res[i][j] %= mod;
                }
            }
        }
        return res;
    }
 
    Mat operator+(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = m[i][j] + m2[i][j];
                if (res[i][j] >= mod) res[i][j] %= mod;
            }
        }
        return res;
    }
    
    Mat operator-(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = m[i][j] - m2[i][j];
                if (res[i][j] >= mod) res[i][j] %= mod;
            }
        }
        return res;
    }
 
    static Mat pow(Mat a, ll b) {
        Mat res = e();
        while (b > 0) {
            if (b & 1) {
                res = res * a;
            }
            a = a * a;
            b >>= 1;
        }
        return res;
    }
 
    static Mat e() {
        Mat id;
        for (int i = 0; i < n; i++) id[i][i]++;
        return id;
    }
};
 
Mat comb(Mat a, Mat b) {
    return a * b;
}
 
Mat e() {
    return Mat::e();
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
    int r, n, m; cin >> r >> n >> m; mod = r;
    vector<Mat> a(n);
    SegTree<Mat, comb, e> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0][0] >> a[i][0][1] >> a[i][1][0] >> a[i][1][1];
    }
    st.build(a, n);
    while (m--) {
        int l, r; cin >> l >> r;
        Mat mat = st.query(l - 1, r);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}