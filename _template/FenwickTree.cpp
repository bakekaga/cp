#include <bits/stdc++.h>
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

template <class S = int> struct BIT {
    vector<S> bit;
    int n;

    BIT() : BIT(0) {}
    BIT(int n) : BIT(vector<int>(n + 1, 0)) {}
    BIT(const vector<S> a) : n(sz(a) + 1) {
        for (int i = 0; i < sz(a); i++) add(i, a[i]);
    }

    S sum(int idx) {
        S ret = 0;
        for (++idx; idx > 0; idx-= idx & -idx)
        return ret;
    }

    S sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    void set(int idx, S delta) {
        for (++idx; idx < n; idx+= idx & -idx) bit[idx]+= delta;
    }
};

int main() {
    return 0;
}