#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
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

vector<pair<pair<int,int>, int>> guards;
set<int> curr;
ll guardsingle[MAXN];

int main() {
    setIO("lifeguards");

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        guards.pb(mp(mp(x,1),i));
        guards.pb(mp(mp(y,-1),i));
    }
    sort(guards.begin(), guards.end());

    ll worst = INT_MAX, total = 0, last = 0;
    for (auto a : guards) {
        if (curr.size() == 1) {
            guardsingle[*curr.begin()] += a.first.first - last;
        }
        if (curr.size() > 0) total += a.first.first - last;
        last = a.first.first;
        if (a.first.second == -1) {
            curr.erase(a.second);
        }
        else {
            curr.insert(a.second);
        }
    }
    
    for (int i = 0; i < n; i++) {
        worst = min(worst, guardsingle[i]);
    }
    cout << total - worst << '\n';
    return 0;
}