// MATRIX 
#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

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
                    if (res[i][j] >= MOD) res[i][j] %= MOD;
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
                if (res[i][j] >= MOD) res[i][j] %= MOD;
            }
        }
        return res;
    }
    
    Mat operator-(const Mat &m2) {
        Mat res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = m[i][j] - m2[i][j];
                if (res[i][j] >= MOD) res[i][j] %= MOD;
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
