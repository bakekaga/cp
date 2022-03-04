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
	int n, cnt = 0; ll x;
	cin >> n >> x;
	vector<ll> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());
	int i = 0, j = n - 1;
	for (; i < j; j--) {
		if (p[i] + p[j] <= x) i++;
		cnt++;
	}
	cout << cnt + (j == i) << '\n';
	return 0;
}