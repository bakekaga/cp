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

vector<int> adj[MAXN];
bool vis[MAXN];
int ind[MAXN];
vector<int> ord;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; ll k;
	cin >> n >> m >> k;
	vector<pair<ll, ll>> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = a[i].first + k;
		a[i].first-= k;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int cnt = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && b[j] < a[i].first) j++;
		if (j == m) break;
		if (a[i].first <= b[j] && b[j] <= a[i].second) {
			cnt++;
			j++;
		}
	}
	cout << cnt << '\n';
	return 0;
}