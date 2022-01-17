#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

struct mi {
    int v;
    mi() : mi(0) {}
    mi(int _v) : v(_v) {
        if (v >= MOD) v -= MOD;
        if (v < 0) v += MOD;
    }
    mi(ll _v) : mi((int)(_v % MOD)) {}

    mi operator+(const mi &m2) const { return mi(v + m2.v); }
    mi operator-(const mi &m2) const { return mi(v - m2.v); }
    mi operator*(const mi &m2) const { return mi((ll) v * m2.v); }
    mi operator/(const mi &m2) const { return mi((ll) v * m2.inv().v); }
    mi &operator+=(const mi &m2) { return *this = *this + m2; }
    mi &operator-=(const mi &m2) { return *this = *this - m2; }
    mi &operator*=(const mi &m2) { return *this = *this * m2; }
    mi &operator/=(const mi &m2) { return *this = *this / m2; }

    mi pow(ll e) const {
        mi res = 1;
        mi n = *this;
        while (e > 0) {
            if (e & 1) res *= n;
            n *= n;
            e >>= 1;
        }
        return res;
    }
    
    mi inv() const {
        return pow(MOD - 2);
    }
};

struct Mat {
    const static int n = 2;
    mi m[n][n];
    Mat() { memset(m, 0, sizeof m);}

    mi *operator[](const int &x) { return m[x]; }
    const mi *operator[](const int &x) const { return m[x]; }

    Mat operator*(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < n; a++) {
                    res[i][j] += m[i][a] * m2[a][j];
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
            }
        }
        return res;
    }
    
    Mat operator-(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = m[i][j] - m2[i][j];
            }
        }
        return res;
    }

    Mat &operator+=(const Mat &m2) { return *this = *this + m2; }
    Mat &operator-=(const Mat &m2) { return *this = *this - m2; }
    Mat &operator*=(const Mat &m2) { return *this = *this * m2; }
    
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
        for (int i = 0; i < n; i++) id[i][i] = 1;
        return id;
    }
};
