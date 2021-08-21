#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define f first
#define s second
 
using namespace std;
 
int psum[MAXN];
 
int main() {
    int n, q, x, y; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x; psum[i + 1] = psum[i] ^ x;
    }
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << (psum[y] ^ psum[x - 1]) << '\n';
    }
    return 0;
}