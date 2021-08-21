#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;
 
int comb(int a, int b) {
    return min(a, b);
}
 
int initial() {
    return INT_MAX;
}
 
template<class T, T (*comb)(T, T), T (*initial)()> struct SparseTable {
    constexpr static int K = 25; // K >= log(MAXN), K = 25 is good for MAXN <= 1e7
    T st[MAXN][K + 1]; // st[i][j] stores ans for range [i, (1<<(j-1)) - 1]
    int logN[MAXN + 1];
    
    void build(vector<T> &a, int n) {
		for (int i = 1; i <= n; i++)
    		st[i][0] = a[i];
 
		for (int j = 1; j <= K; j++)
		    for (int i = 0; i + (1<<j) <= n; i++)
        		st[i][j] = comb(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
        		
        logN[1] = 0;
        for (int i = 2; i <= MAXN; i++) logN[i] = logN[(i>>1)] + 1;
    }
    
    T query(int l, int r) {
        int j = logN[r - l + 1];
        return comb(st[l][j], st[r - (1<<j) + 1][j]);
    }
};
 
int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    SparseTable<int, comb, initial> st;
    st.build(a, n + 1);
    
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
    return 0;
}