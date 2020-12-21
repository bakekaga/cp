#include <bits/stdc++.h>

#define mp make_pair
#define MAXN 100005
#define pb push_back
#define sz(x) int(x.size())
 
using namespace std;
 
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int h[MAXN];
int p[MAXN];
int s[MAXN];

int main() {
	setIO("hps");
    int n, res = 0;
    char a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 'P') {
            p[i] = p[i-1];
            h[i] = h[i-1];
            s[i] = s[i-1]+1;
        }
        else if (a == 'H') {
            p[i] = p[i-1]+1; 
            h[i] = h[i-1];
            s[i] = s[i-1];
        }
        else if (a == 'S') {
        	p[i] = p[i-1];
            h[i] = h[i-1]+1;
            s[i] = s[i-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        res = max(res,p[i]+h[n]-h[i]);
        res = max(res,p[i]+s[n]-s[i]);
        res = max(res,h[i]+p[n]-p[i]);
        res = max(res,h[i]+s[n]-s[i]);
        res = max(res,s[i]+p[n]-p[i]);
        res = max(res,s[i]+h[n]-h[i]);
    }

    cout << res << '\n';
}