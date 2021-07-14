#include <bits/stdc++.h>
#define MAXN 50005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

int psums[MAXN];
int first[7];
int last[7];

int main() {
    setIO("div7");
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        psums[i + 1] = psums[i] + x;
        psums[i + 1] %= 7;
        if (first[psums[i + 1]] == 0) first[psums[i + 1]] = i + 1;
        last[psums[i + 1]] = i + 1;
    }

    int ret = 0;
    for (int i = 0; i < 7; i++) {
        ret = max(ret, last[i] - first[i]);
    }
    cout << ret << '\n';
    return 0;
}