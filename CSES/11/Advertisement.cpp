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
    int n; cin >> n;
    vector<ll> heights(n + 1);
    for (int i = 0; i < n; i++) cin >> heights[i];
    ll ans = 0;
    stack<int> st;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
			int lastInd = st.top();
			st.pop();
            if (st.empty()) {
				ans = max(ans, heights[lastInd] * i);
			}
			else {
				ans = max(ans, heights[lastInd] * (i - st.top() - 1));
			}
        }
        st.push(i);
    }
    cout << ans << '\n';
    return 0;
}