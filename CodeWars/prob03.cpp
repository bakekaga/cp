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
	double pts, fga, fta; cin >> pts >> fga >> fta;
	double out = 100 * pts / (2 * (fga + (0.44 * fta)));
	cout << round(out * 100) / 100 << "%\n";
	return 0;
}