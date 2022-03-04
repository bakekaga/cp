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
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end());
	int prev = -1, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].second >= prev) {
			res++;
			prev = a[i].first;
		}
	}
	cout << res << '\n';
	return 0;
}