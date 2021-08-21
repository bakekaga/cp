// Handle: bakekaga
// Problem Name: 1530C Pursuit
// URL: https://codeforces.com/contest/1530/problem/C

#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
#define endl '\n'
 
using namespace std;
 
void solve() {
    int n, in; cin >> n;
    priority_queue<ll> a, b;
    priority_queue<ll, vector<ll>, greater<ll>> ra;
    for (int i = 0; i < n; i++) {
        cin >> in;
        a.push(in);
    }
    for (int i = 0; i < n; i++) {
        cin >> in;
        b.push(in);
    }
    ll ret = 0, reti = 0;
    int amt = 0;
    while (amt < n - n / 4) {
        ret+= a.top();
        reti+= b.top();
        ra.push(a.top());
        a.pop();
        b.pop();
        amt++;
    }
    int i = n;
    while (ret < reti) {
        i++;
        if (i % 4 == 0 && !ra.empty()) {
            ret-= ra.top();
            ra.pop();
            amt--;
        }
        while (amt < i - i / 4) {
            ret+= 100;
            if (!b.empty() && i % 4 != 0) {
                reti+= b.top();
                b.pop();
            }
            amt++;
        }
    }
    cout << i - n << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
