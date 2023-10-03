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
	string s;
	cin >> s;
	int bestR = 1;
	for (int i = 2; i * i <= sz(s); i++) {
		if (!(sz(s) % i)) {
			bestR = i;
		}
	}
	for (int r = 0; r < bestR; r++) {
		for (int c = 0; c < sz(s) / bestR; c++) {
			cout << s[c * bestR + r];
		}
	}
	cout << '\n';
}