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
	string line;
	while (getline(cin, line)) {
		ll n = stoi(line, nullptr, 10);
		ll cur = 1;
		int cnt = 0;
		while (cur % n != 0LL) {
			cnt++;
			cur = 10LL * cur + 1LL;
		}
		cout << cnt + 1 << '\n';
	}
	return 0;
}
