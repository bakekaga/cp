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
	ios::sync_with_stdio(0); cin.tie(0);
	int n; ll x;
	cin >> n >> x;
	vector<pair<ll, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i].first + a[j].first == x) {
			cout << a[i].second << ' ' << a[j].second << '\n';
			return 0;
		}
		while (i < j && a[i].first + a[j].first < x) i++;
		while (i < j && a[i].first + a[j].first > x) j--;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}