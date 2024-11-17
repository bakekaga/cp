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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    set<ll> bad;
    ll start;
    for (int i = 1; i <= n; i++) {
        if (i != k) {
            ll x;
            cin >> x;
            bad.insert(x);
        }
        else {
            cin >> start;
        }
    }
    vector<pair<char, ll>> ops(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> ops[i].first >> ops[i].second;
    }

    queue<ll> bfs;
    bfs.push(start);
    
    map<ll, pair<int, ll>> par;
    par[start] = {-1, start};

    while (!bfs.empty()) {
        ll curVal = bfs.front();
        bfs.pop();
        if (!bad.count(curVal)) {
            vector<int> opsOut;
            while (par[curVal].first != -1) {
                opsOut.push_back(par[curVal].first);
                curVal = par[curVal].second;
            }
            cout << sz(opsOut) << '\n';
            for (int i = sz(opsOut) - 1; i >= 0; i--) {
                cout << opsOut[i] << '\n';
            }
            return 0;
        }
        
        for (int i = 1; i <= m; i++) {
            char op = ops[i].first;
            ll val = ops[i].second;
            ll newVal = curVal;
            if (op == '+') {
                newVal += val;
            }
            else if (op == '-') {
                newVal -= val;
            }
            else if (op == '*') {
                newVal *= val;
            }
            else if (op == '/') {
                newVal /= val;
            }
            if (par.count(newVal) || newVal < 0) continue;
            par[newVal] = {i, curVal};
            bfs.push(newVal);
        }
    }
    cout << -1 << '\n';

    return 0;
}