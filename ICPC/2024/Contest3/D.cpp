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
	int n, A, B; cin >> n >> A >> B;
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (A < 0) {
		sort(s.rbegin(), s.rend());
	}
	else {
		sort(s.begin(), s.end());
	}
	ll out = 0;
	for (int i = 0; i < n; i++) {
		out += (i + 1) * (A * s[i] + B);
	}
	cout << out << '\n';
	return 0;
}