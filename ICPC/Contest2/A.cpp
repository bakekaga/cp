#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2501;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int adj[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> deg(n + 1);
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << " " << i << endl;
		cin >> deg[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << "? " << 2 << " " << i << " " << j << endl;
			int x; cin >> x;
			if (x != deg[i] + deg[j]) {
				adj[i][j]++;
				adj[j][i]++;
			}
		}
	}
	cout << "!\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}