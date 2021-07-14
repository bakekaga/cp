#include <bits/stdc++.h>
#define MAXN 2505
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

void setIO(string prob = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(prob)) {
        freopen((prob + ".in").c_str(), "r", stdin);
        freopen((prob + ".out").c_str(), "w", stdout);
    }
}

struct Cow {
    ll x, y; int id;
    bool stopped;
    char dir;
};

bool cmp1(const Cow &a, const Cow &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(const Cow &a, const Cow &b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

vector<Cow> arrN;
vector<Cow> arrE;
int arr[MAXN];

int main() {
    setIO();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        Cow c; c.id = i;
        cin >> c.dir >> c.x >> c.y;
        if (c.dir == 'E') arrE.pb(c);
        else arrN.pb(c);
    }
    sort(arrN.begin(), arrN.end(), cmp1);
    sort(arrE.begin(), arrE.end(), cmp2);

    for (int i = 0; i < arrN.size(); i++) {
        for (int j = 0; j < arrE.size(); j++) {
            if (!arrN[i].stopped && !arrE[j].stopped && arrN[i].y <= arrE[j].y && arrN[i].x >= arrE[j].x) {
                if (-(arrN[i].y - arrE[j].y) > (arrN[i].x - arrE[j].x)) {
                    arr[arrE[j].id]+= arr[arrN[i].id] + 1;
                    arrN[i].stopped = true;
                }
                else if (-(arrN[i].y - arrE[j].y) < (arrN[i].x - arrE[j].x)) {
                    arr[arrN[i].id]+= arr[arrE[j].id] + 1;
                    arrE[j].stopped = true;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}