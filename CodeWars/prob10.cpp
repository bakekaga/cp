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
	string s; cin >> s;
	stack<char> st;
	bool ok = true;
	int cntl = 0, cntr = 0, cntok = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '(') {
			st.push('(');
			cntl++;
		}
		else if (s[i] == ')') {
			if (!st.empty()) {
				st.pop();
				cntok++;
			}
			else {
				ok = false;
			}
			cntr++;
		}
	}
	cout << "Total left: " << cntl << "\nTotal right: " << cntr;
	cout << "\nTotal pairs: " << cntok << (ok && st.empty() ? "\nBalanced\n" : "\nUnbalanced\n");
	return 0;
}