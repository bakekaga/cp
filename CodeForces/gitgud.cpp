#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

ll chickens[MAXN];
ll suff_sum[MAXN];
ll suff_min[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chickens[i];
	}
	// suff_sum[i] == sum when K == i
	suff_min[n] = INF;
	pair<ll, ll> maxC = mp(0, 1);
	for (int i = n - 1; i >= 1; i--) {
		suff_sum[i] = suff_sum[i + 1] + chickens[i];
		suff_min[i] = min(suff_min[i + 1], chickens[i]);
		if (i < n - 1 && (suff_sum[i] - suff_min[i]) * maxC.second > maxC.first * (n - i - 1)) {
			maxC = mp(suff_sum[i] - suff_min[i], n - i - 1);
		}
	}
	vector<int> out;
	for (int i = 1; i < n - 1; i++) {
		if ((suff_sum[i] - suff_min[i]) * maxC.second == maxC.first * (n - i - 1)) {
			out.pb(i);
		}
	}
	for (int item : out) {
		cout << item << '\n';
	}
	return 0;
}