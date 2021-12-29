#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

struct S { int id, p; bool liked; };

bool cmp(const S &a, const S &b) {
    return a.liked == b.liked ? a.p < b.p : !a.liked;
}

void solve() {
    int n; cin >> n;
    vector<S> perm(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> perm[i].p;
        perm[i].id = i;
    }
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        perm[i].liked = s[i - 1] - '0';
    }
    sort(perm.begin(), perm.end(), cmp);
    vector<int> out(n + 1);
    for (int i = 1; i <= n; i++) {
        out[perm[i].id] = i;
    }
    for (int i = 1; i <= n; i++) cout << out[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}