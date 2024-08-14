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
		string s; cin >> s;
		string out = "NO\n";
		if (sz(s) < 3 || s[0] != '1' || s[1] != '0' || s[2] == '0') cout << out;
		else {
			if (stoi(s.substr(2)) >= 2) {
				out = "YES\n";
			}
			cout << out;
		}
	}	
	return 0;
}
