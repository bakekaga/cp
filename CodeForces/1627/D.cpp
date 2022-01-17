#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

ll gcd(ll n, ll m) {
    if (n < m) swap(n, m);
    for (int i = 0; i < 10; ++i) {
        ll t = n - m;
        bool q = m > t;
        n = q ? m : t;
        m = q ? t : m;
        if (m == 0) return n;
    }
    return gcd(m, n % m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(MAXN);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[a] = a;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j+= i) {
            arr[i] = gcd(arr[i], arr[j]);
        }
    }
    int cnt = 0;
    for (int i = 1; i < MAXN; i++) {
        if (arr[i] == i) cnt++;
    }
    cout << cnt - n << '\n';
    return 0;
}