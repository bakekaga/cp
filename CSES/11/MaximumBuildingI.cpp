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
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> heights(m + 1);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			heights[j] = (arr[i][j] == '.' ? heights[j] + 1 : 0);
		}
		stack<int> st;
		for (int j = 0; j <= m; j++) {
			while (!st.empty() && heights[j] <= heights[st.top()]) {
				int lastInd = st.top();
				st.pop();
				if (st.empty()) {
					mx = max(mx, heights[lastInd] * j);
				}
				else {
					mx = max(mx, heights[lastInd] * (j - st.top() - 1));
				}
			}
			st.push(j);
		}
	}
	cout << mx << '\n';
	return 0;
}