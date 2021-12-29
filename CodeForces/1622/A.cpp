#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int arr[3];

void solve() {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[1] == arr[2] && arr[0] % 2 == 0 || (arr[0] == arr[1] && arr[2] % 2 == 0) || (arr[0] + arr[1] == arr[2])) cout << "YES\n";
    else cout << "NO\n"; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}