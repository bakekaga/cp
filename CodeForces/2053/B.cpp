#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T = int> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> arr(n);
	ordered_set<> covered;
	string out(n, '1');
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = i;
	}
	sort(arr.begin(), arr.end(), [](const array<int, 3> &a, const array<int, 3> &b) {
		if (a[1] - a[0] == b[1] - b[0]) {
			return a < b;
		}
		return a[1] - a[0] < b[1] - b[0];
	});
	for (int i = 0; i < n; i++) {
		if (arr[i][1] == arr[i][0]) {
			covered.insert(arr[i][0]);
			if (i && arr[i][0] == arr[i - 1][0]) {
				out[arr[i][2]] = out[arr[i - 1][2]] = '0';
			}
		}
		else if (covered.find(arr[i][1]) != covered.end() && covered.find(arr[i][0]) != covered.end() && covered.order_of_key(arr[i][1]) - covered.order_of_key(arr[i][0]) == arr[i][1] - arr[i][0]) {
			out[arr[i][2]] = '0';
		}
	}
	cout << out << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
