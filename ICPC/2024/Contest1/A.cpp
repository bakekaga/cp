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
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	int curStart = 0, mx = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i && a[i] <= a[i - 1]) {
			mx = max(mx, i - curStart);
			curStart = i;
		}
	}
	cout << max(mx, n - curStart) << '\n';
	return 0;
}