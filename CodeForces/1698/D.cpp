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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			cout << "? " << l << " " << mid << endl;
			vector<int> a(mid - l + 1);
			int cnt = 0;
			for (int i = 0; i < sz(a); i++) {
				cin >> a[i];
				if (a[i] == -1) {
					return 0;
				}
				if (a[i] <= mid && a[i] >= l) cnt++;
			}
			if (cnt & 1) r = mid;
			else l = mid + 1;
		}
		cout << "! " << l << endl;
	}
	return 0;
}