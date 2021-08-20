#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

int haybales[MAXN];

int main() {
    setIO("haybales");
    
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> haybales[i];
    
    sort(haybales, haybales + n);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int left = lower_bound(haybales, haybales + n, a) - haybales;
        int right = upper_bound(haybales, haybales + n, b) - haybales;
        cout << right - left << '\n';
    }
    return 0;
}