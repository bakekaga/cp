#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 501;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	vector<string> v(4);
	for (int i = 0; i < 4; i++) cin >> v[i];
	while (t--) {
		string word; cin >> word;
		bool ok = false;
		do {
			for (int i = 0; i < word.length(); i++) {
				bool found = false;
				for (int j = 0; j < 6; j++) {
					if (word[i] == v[i][j]) {
						found = true;
						break;
					}
				}
				if (found) ok = true;
			}
		} while (next_permutation(v.begin(), v.end()));
	}
}