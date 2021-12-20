#include <bits/stdc++.h>
#define MAXN 50005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int first[7];
int last[7];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n, x, psums = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        psums+= x;
        psums%= 7;
        if (first[psums] == 0) first[psums] = i + 1;
        last[psums] = i + 1;
    }

    int ret = 0;
    for (int i = 0; i < 7; i++) {
        ret = max(ret, last[i] - first[i]);
    }
    cout << ret << '\n';
    return 0;
}