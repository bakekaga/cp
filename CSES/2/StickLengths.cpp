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
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<ll> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());
	ll sum = 0;
	for (int i = 0; i < n; i++) sum+= abs(p[n / 2] - p[i]);
	cout << sum << '\n';
	return 0;
}