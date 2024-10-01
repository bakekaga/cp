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
	priority_queue<ll> q;
	for (int i = 0; i < n; i++) {
		ll val;
		cin >> val;
		q.push(val);
	}
	ll tot = 0;
	for (int tt = 0; tt < n; tt++) {
		ll b; cin >> b;
		tot += b;
		ll cur = q.top();
		cur -= (cur + tot) / 2;
		q.pop();
		q.push(cur);
	}
	ll out = 0;
	while (!q.empty()) {
		out += tot + q.top();
		q.pop();
	}
	cout << out << '\n';
	return 0;
}