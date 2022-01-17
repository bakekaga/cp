#include <bits/stdc++.h>
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

    int bit_search(int v) {
        int sum = 0, pos = 0, log = 0;
        while ((1U << log) < (unsigned int)(n)) log++;
        for (int i = log; i >= 0; i--) {
            if (pos + (1 << i) < n and sum + bit[pos + (1 << i)] < v) {
                sum += bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
    }
};

int main() {
    return 0;
}