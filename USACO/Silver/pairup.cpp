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
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    
    int n; cin >> n;
    vector<pair<ll, ll>> cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i].second >> cows[i].first;
    sort(cows.begin(), cows.end());
    
    ll sum = 0;
    for (int i = 0, j = n - 1; i <= j;) {
        sum = max(sum, cows[i].first + cows[j].first);
        if (cows[i].second > cows[j].second) {
            cows[i].second-= cows[j].second;
            j--;
        }
        else if (cows[j].second > cows[i].second) {
            cows[j].second-= cows[i].second;
            i++;
        }
        else {
            i++;
            j--;
        }
    }
    cout << sum << '\n';
    return 0;
}