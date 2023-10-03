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

void solve() {
	int mn = 24, cnt = 0;
	stack<pair<string, int>> games;
	string cur; cin >> cur;
	for (int i = 0; i < 23; i++) {
		if (cur[i] == 'o') cnt++;
	}
	games.push(mp(cur, cnt));
	while (!games.empty()) {
		cur = games.top().first;
		cnt = games.top().second;
		mn = min(cnt, mn);
		games.pop();
		vector<pair<int, int>> moves;
		for (int i = 0; i < 21; i++) {
			if (cur[i] == 'o' && cur[i + 1] == 'o' && cur[i + 2] == '-') {
				moves.pb(mp(i, 1));
			}
		}
		for (int i = 22; i >= 2; i++) {
			if (cur[i] == 'o' && cur[i - 1] == 'o' && cur[i - 2] == '-') {
				moves.pb(mp(i, -1));
			}
		}
		for (int i = 0; i < sz(moves); i++) {
			string mod = cur;
			int modCnt = cnt - 1, sgn = moves[i].second;
			mod[moves[i].first + 2 * sgn] = 'o';
			mod[moves[i].first] = mod[moves[i].first + 1 * sgn] = '-';
			games.push(mp(mod, modCnt));
		}
	}
	cout << mn << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}