#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, q; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> q;
        ll ret = 0;
        vector<ll> v(n), psums(n + 1), sweetsums(n + 1);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];

            if (i % 2 == 0) {
                psums[i + 1] = psums[i] + v[i];
                sweetsums[i + 1] = sweetsums[i] + (i + 1) * v[i];
            }
            else {
                psums[i + 1] = psums[i] - v[i];
                sweetsums[i + 1] = sweetsums[i] - (i + 1) * v[i];
            }
        }
        char c; int a, b;
        while (q--) {
            cin >> c >> a >> b;
            if (c == 'U') {
                for (int i = a; i <= n; i++) {
                    if (a % 2 == 0) {
                        psums[i]-= b - v[a - 1];
                        sweetsums[i]-= a * (b - v[a - 1]);
                    }
                    else {
                        psums[i]+= b - v[a - 1];
                        sweetsums[i]+= a * (b - v[a - 1]);
                    }
                }
                v[a - 1] = b;
            }
            if (c == 'Q') {
                if (a % 2 == 0) ret-= sweetsums[b] - sweetsums[a - 1] - (a - 1) * (psums[b] - psums[a - 1]);
                else ret+= sweetsums[b] - sweetsums[a - 1] - (a - 1) * (psums[b] - psums[a - 1]);
            }
        }
		cout << "Case #" << tt << ": " << ret << '\n';
    }
    return 0;
}