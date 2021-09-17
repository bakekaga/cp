#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 100000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, q, x, y, bad = 0; cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cnt[min(x, y)]++;
        if (cnt[min(x, y)] == 1) bad++;
    }

    cin >> q;
    while (q--) {
        int id; cin >> id;
        if (id == 1) {
            cin >> x >> y;
            cnt[min(x, y)]++;
            if (cnt[min(x, y)] == 1) bad++;
        }
        else if (id == 2) {
            cin >> x >> y;
            cnt[min(x, y)]--;
            if (cnt[min(x, y)] == 0) bad--;
        }
        else {
            cout << n - bad << '\n';
        }
    }
    return 0;
}
