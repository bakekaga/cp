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
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	if (s > t) swap(s, t);
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> heights(m + 1);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		vector<int> psums(m + 1);
		for (int j = 0; j < m; j++) {
			heights[j] = (arr[i][j] == '.' ? heights[j] + 1 : 0);
			if (i < n - 1) {
				psums[j + 1] = psums[j] + (arr[i + 1][j] == '0');
			}
		}
		stack<int> st;
		for (int j = 0; j <= m; j++) {
			while (!st.empty() && heights[j] <= heights[st.top()]) {
				int lastInd = st.top();
				st.pop();
				if (heights[j] == heights[lastInd]) {
					continue;
				}
				else if (st.empty()) {
					bool ok = min(heights[lastInd], j) >= s && max(heights[lastInd], j) >= t;
					ok &= i == n - 1 || psums[j] > 0;
					cnt += ok;
				}
				else {
					bool ok = min(heights[lastInd], j - st.top() - 1) >= s && max(heights[lastInd], j - st.top() - 1) >= t;
					ok &= i == n - 1 || psums[j] > psums[st.top() + 1];
					cnt += ok;
				}
			}
			st.push(j);
		}
	}
	cout << cnt << '\n';
	return 0;
}