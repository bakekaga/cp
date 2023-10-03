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
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int, array<int, 2>> diffs;
		diffs[INF] = {INF, 0};
		diffs[-INF] = {0, -INF};
		for (int i = 0; i < (1 << (n / 2)); i++) {
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < n / 2; j++) {
				if (i & (1 << j)) {
					sum1 += a[j];
				}
				else {
					sum2 += a[j];
				}
			}
			int cur = sum1 - sum2;
			diffs[cur] = {sum1, sum2};
			diffs[-cur] = {sum2, sum1};
		}
		array<int, 2> out = {INF, -INF};
		for (int i = 0; i < (1 << (n - n / 2)); i++) {
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < n - n / 2; j++) {
				if (i & (1 << j)) {
					sum1 += a[n / 2 + j];
				}
				else {
					sum2 += a[n / 2 + j];
				}
			}
			int cur = sum1 - sum2;
			auto lb = diffs.lower_bound(cur);
			if (out[0] - out[1] > lb->first - cur) {
				out[0] = sum2 + lb->second[0];
				out[1] = sum1 + lb->second[1];
			}
			lb = diffs.lower_bound(-cur);
			if (out[0] - out[1] > lb->first + cur) {
				out[0] = sum1 + lb->second[0];
				out[1] = sum2 + lb->second[1];
			}
		}
		cout << out[0] << ' ' << out[1] << '\n';
	}
	return 0;
}