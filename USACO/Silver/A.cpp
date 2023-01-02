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

struct E {
	int a, id;
	ll v, loss;
	vector<int> from;
};

bool cmp(const E &x, const E &y) {
	return x.loss == y.loss ? x.id < y.id : x.loss < y.loss;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; ll ans = 0;
	vector<E> edges(n + 1);
	set<E, decltype(cmp)*> ord(cmp);
	for (int i = 1; i <= n; i++) {
		cin >> edges[i].a >> edges[i].v;
		edges[edges[i].a].from.pb(i);
		edges[edges[i].a].loss+= edges[i].v;
		edges[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		ord.insert(edges[i]);
	}
	while (!ord.empty()) {
		E cur = *ord.begin();
		ans+= cur.v;
		if (ord.find(edges[cur.a]) != ord.end()) {
			ord.erase(edges[cur.a]);
			edges[cur.a].loss-= cur.v;
			ord.insert(edges[cur.a]);
		}
		for (int x : cur.from) ord.erase(edges[x]);
		ord.erase(cur);
	}
	cout << ans << '\n';
	return 0;
}