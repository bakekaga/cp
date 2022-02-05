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
 
ll v[MAXN];
 
ll kadane(int n) {
    ll best = INT_MIN, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(v[k], sum + v[k]);
        best = max(best, sum);
    }
    return best;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << kadane(n) << '\n';
    return 0;
}