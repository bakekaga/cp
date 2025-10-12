#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 5e4 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int logN[MAXN + 1];
constexpr static int K = 16;
int st[MAXN][K + 1];
int v[MAXN];

int comb(int a, int b) {
	if (v[a] > v[b]) {
		return b;
	}
	return a;
}

void build(int n) {
	for (int i = 0; i < n; i++) st[i][0] = i;

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = comb(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int j = logN[r - l + 1];
	return comb(st[l][j], st[r - (1 << j) + 1][j]);
}

bool check(int l, int r, ll x) {
	if (l >= r) {
		return 1;
	}
	int id_mn = query(l, r);
	bool ok = true;
	if (id_mn > l) {
		int left_id = query(l, id_mn - 1);
		ok &= (v[left_id] + x) % (v[id_mn] + x) == 0;
	}
	if (id_mn < r) {
		int right_id = query(id_mn + 1, r);
		ok &= (v[right_id] + x) % (v[id_mn] + x) == 0;
	}
	if (ok) {
		return check(l, id_mn - 1, x) && check(id_mn + 1, r, x);
	}
	return 0;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll delta;
	int smallest = -1;
	for (int i = 1; i < n; i++) {
		delta = abs(v[i] - v[i - 1]);
		if (delta == 0) continue;
		smallest = min(v[i], v[i - 1]);
		break;
	}
	if (smallest == -1) {
		cout << k << " " << k * (k + 1LL) / 2 << "\n";
		return;
	}
	build(n);
	vector<ll> div;
	for (ll i = 1; i * i <= delta; i++) {
		if (delta % i == 0) {
			div.push_back(i);
			if (delta / i != i) div.push_back(delta / i);
		}
	}
	int ans = 0;
	ll sum = 0;
	for (ll d : div) {
		ll x = delta / d - smallest;
		if (x < 1 or x > k) continue;
		if (check(0, n - 1, x)) {
			ans++;
			sum += x;
		}
	}
	cout << ans << " " << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	logN[1] = 0;
	for (int i = 2; i <= MAXN; i++) {
		logN[i] = logN[(i >> 1)] + 1;
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
