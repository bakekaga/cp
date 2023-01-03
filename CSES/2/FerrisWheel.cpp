#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

ll p[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0; ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	for (int i = n - 1, j = 0; i >= j; i--) {
		if (p[i] + p[j] <= x) j++;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}