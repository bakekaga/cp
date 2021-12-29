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
 
template<class T = int> struct SparseTable {
    constexpr static int K = 25; // K >= log(maxn), K = 25 is good for maxn <= 1e7
    T st[maxn][K+1]; // st[i][j] stores ans for range [i, (1<<(j-1)) - 1]
    int logN[maxn+1];
    
    T comb(T a, T b) {
        return min(a, b);
    }
    
    T e() {
        return INT_MAX;
    }

    RMQ() : RMQ(0) {}
    explicit RMQ(int n) : RMQ(vector<T>(n, e())) {}
    explicit RMQ(const vector<T> &a) {
        for (int i = 1; i < a.size(); i++) st[i][0] = a[i];
 
		for (int j = 1; j <= K; j++)
		    for (int i = 0; i + (1<<j) < a.size(); i++)
        		st[i][j] = comb(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
        		
        logN[1] = 0;
        for (int i = 2; i <= maxn; i++) logN[i] = logN[(i>>1)] + 1;
    }
    
    T query(int l, int r) {
        int j = logN[r - l + 1];
        return comb(st[l][j], st[r - (1<<j) + 1][j]);
    }
};