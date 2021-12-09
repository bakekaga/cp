#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size()
#define pb push_back

using namespace std;

struct Event { int ind, val; };

bool operator<(Event a, Event b) { return a.val == b.val ? a.ind < b.ind : a.val < b.val; }

Event arr[MAXN];

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].val;
		arr[i].ind = i;
	}
	sort(arr, arr + n);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i].ind - i);
	}
	cout << ans + 1 << '\n';
	return 0;
}