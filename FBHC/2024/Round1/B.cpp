#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 10000005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
	freopen("B.txt", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	
	vector<int> lp(MAXN);
	vector<int> pr;
	set<int> primes;

	for (int i = 2; i <= MAXN; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
			primes.insert(i);
		}
		for (int j = 0; i * pr[j] <= MAXN; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n; cin >> n;
		int tot = (n >= 5);
		// go through all primes < n
		for (int i : pr) {
			if (i + 2 > n) {
				break;
			}
			// test if this prime works
			if (primes.count(i + 2)) {
				tot++;
			}
		}
		cout << "Case #" << tt << ": " << tot << '\n';
	}
	return 0;
}