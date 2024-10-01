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
	if (n <= 2) {
		cout << "4\n";
	}
	else if (n % 2 == 0) {
		cout << n << '\n';
	}
	else {
		bool found = false;
		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0) {
				found = true;
				break;
			}
		}
		cout << (found ? n : n + 1) << '\n';
	}
	return 0;
}