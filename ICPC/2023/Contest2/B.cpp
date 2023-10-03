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
	char dom; cin >> dom;
	ll tot = 0;
	map<int, array<int, 2>> scores;
	scores['A'] = {11, 11};
	scores['K'] = {4, 4};
	scores['Q'] = {3, 3};
	scores['J'] = {20, 2};
	scores['T'] = {10, 10};
	scores['9'] = {14, 0};
	scores['7'] = scores['8'] = {0, 0};
	for (int i = 0; i < 4 * n; i++) {
		string s;
		cin >> s;
		if (s[1] == dom) {
			tot += scores[s[0]][0];
		}
		else {
			tot += scores[s[0]][1];
		}
	}
	cout << tot << '\n';
}