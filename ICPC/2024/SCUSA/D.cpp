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
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 1; i <= 2 * n; i++) {
        if (find(a.begin(), a.end(), i) == a.end()) {
            b.push_back(i);
        }
    }
	
	auto calc = [&n](vector<int> &a, vector<int> &b) {
		set<int> res;
		for (int i : b) {
			res.insert(i);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			auto best = lower_bound(res.begin(), res.end(), a[i]);
			if (best != res.begin()) {
				cnt++;
				res.erase(--best);
			}
		}
		return cnt;
	};

    int mx = calc(a, b);
    int mn = n - calc(b, a);
    cout << mn << ' ' << mx << '\n';
    return 0;
}