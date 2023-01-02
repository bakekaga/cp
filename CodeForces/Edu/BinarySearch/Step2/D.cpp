#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;

struct A { int t, z, y; };

A arr[MAXN];

int calcB(int time, int i) {
    int out = time / (arr[i].t * arr[i].z + arr[i].y) * arr[i].z;
    int rem = time % (arr[i].t * arr[i].z + arr[i].y);
    if (rem >= arr[i].t * arr[i].z) out+= arr[i].z;
    else out+= rem / arr[i].t;
    return out;
}

bool ok(int mid, int m, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+= calcB(mid, i);
    }
    return sum >= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].t >> arr[i].z >> arr[i].y;
    }
    int lo = 0, hi = 3e7;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (!ok(mid, m, n)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << '\n';
    for (int i = 0; i < n; i++) {
        int cur = min(m, calcB(lo, i));
        cout << cur << '\n';
        m-= cur;
    }
    return 0;
}