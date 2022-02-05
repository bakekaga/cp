#include <bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

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

mi dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    dp[0] = mi(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            dp[i]+= dp[i - j];
        }
    }
    cout << dp[n].v << '\n';
    return 0;
}