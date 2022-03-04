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
	int n, m; cin >> n >> m;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(-x);
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		auto val = s.lower_bound(-x);
		cout << (val == s.end() ? -1 : -*val) << '\n';
		if (val != s.end()) s.erase(val);
	}
	return 0;
}