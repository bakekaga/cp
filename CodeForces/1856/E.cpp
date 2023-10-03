#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
// void __print(mi x) {cerr << x;}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

template<typename F>
struct y_combinator_result {
    F f;
    template<typename T> explicit y_combinator_result(T &&f) : f(std::forward<T>(f)) {}
    template<typename... Args> decltype(auto) operator()(Args &&...args) {
        return f(ref(*this), std::forward<Args>(args)...);
    }
};
 
template<typename F>
decltype(auto) y_combinator(F &&f) {
    return y_combinator_result<decay_t<F>>(std::forward<F>(f));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].pb(i);
	}

	vector<int> s_sz(n + 1);
	vector<int> ans(n + 1);

	auto dfs = y_combinator([&](auto self, int cur) -> void {
		vector<int> dp(1, 0);

		for (auto nbr : adj[cur]) {
			self(nbr);

			int psz = s_sz[cur];
			s_sz[cur] += s_sz[nbr];
			
			vector<int> nxt(s_sz[cur] + 1, 0);
			for (int bef = 0; bef <= psz; bef++) {
				int aft = psz - bef;
				// subtree of nbr can be before cur in permutation or after
				nxt[bef + s_sz[nbr]] = max(nxt[bef + s_sz[nbr]], dp[bef] + aft * s_sz[nbr]);
				nxt[bef] = max(nxt[bef], dp[bef] + bef * s_sz[nbr]);
			}
			dp = nxt;
		}

		s_sz[cur]++;
		ans[cur] = *max_element(dp.begin(), dp.end());
	});

	dfs(1);
	cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
	return 0;
}