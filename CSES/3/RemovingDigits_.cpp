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
	int n;
	cin >> n;
	int cnt = 0;
	while (n > 0) {
		int mx = 0;
		for (char c : to_string(n)) {
			mx = max(mx, c - '0');
		}
		n -= mx;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}