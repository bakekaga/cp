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
vector<int> prefixmods[MAXN];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, in; ll ret = 0; cin >> n;
    prefixmods[0].pb(0);
    for (int i = 0; i < n; i++) {
        cin >> in;
        psum[i + 1] = psum[i] + in;
        psum[i + 1]%= n;
        if (psum[i + 1] < 0) psum[i + 1]+= n;
        ret+= prefixmods[psum[i + 1]].size();
        prefixmods[psum[i + 1]].pb(i + 1);
    }
    
    cout << ret << '\n';
    return 0;
}