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
	string t, p;
	cin >> t >> p;
	int n = (int) t.size();
	vector<int> ord(n);
	for (int i = 0; i < n; i++) {
		cin >> ord[i];
		ord[i]--;
	}
	int l = 0, r = n;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		vector<int> gone(n);
		for (int i = 0; i < mid; i++) {
			gone[ord[i]]++;
		}
		int j = 0;
		for (int i = 0; i < n && j < p.size(); i++) {
			j += (!gone[i] && t[i] == p[j]);
		}
		if (j < p.size()) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r << '\n';
	return 0;
}