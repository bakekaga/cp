#include <bits/stdc++.h>
#define MAXN 200005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;

    vector<ll> arrA(m + 1), arrB(m + 1), sumA(2 * m + 1), sumB(2 * m + 1);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arrA[a]++;
        arrB[b]++;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            sumA[i + j]+= arrA[i] * arrA[j];
            sumB[i + j]+= arrB[i] * arrB[j];
        }
    }

    ll out = 0;
    for (int i = 0; i <= 2 * m; i++) {
        out+= sumA[i];
        cout << out << '\n';
        out-= sumB[i];
    }
    return 0;
}