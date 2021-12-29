#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int berries[MAXN];
int curB;

bool cmp(const int &a, const int &b) {
    return a % curB > b % curB;
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    
    int n, k, maxB = 0; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> berries[i];
        maxB = max(maxB, berries[i]);
    }

    int ret = 0;
    for (int i = 1; i <= maxB; i++) {
        curB = i;
        int filled = 0;
        for (int j = 0; j < n; j++) {
            filled+= berries[j] / curB;
        }
        if (filled >= k) ret = max(ret, k / 2 * curB);
        else {
            sort(berries, berries + n, cmp);
            int j = max(0, k / 2 - filled), cnt = curB * (filled - k / 2);
            filled = max(filled, k / 2);
            while (j < n && filled < k) {
                cnt+= berries[j] % curB;
                j++;
                filled++;
            }
            ret = max(ret, cnt);
        }
    }
    cout << ret << '\n';
    return 0;
}