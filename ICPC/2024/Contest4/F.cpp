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

array<double, 2> quadratic_formula(int a, int b, int c) {
	if (b * b <= 4 * a * c) {
		return {-1, -1};
	}
	double disc = sqrt(b * b - 4 * a * c);
	double x1 = (-b + disc) / (2 * a);
	double x2 = (-b - disc) / (2 * a);
	return {x1, x2};
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x1, y1, x2, y2, M;
	cin >> x1 >> y1 >> x2 >> y2 >> M;
	int D = 2 * (M * M + x1 * x1 + x2 * x2 - y1 * y1 - y2 * y2) - (y1 + y2) * (y1 + y2);
	auto [xlow, xhigh] = quadratic_formula(4, -4 * (x1 + x2), D);
	cout << xlow << ' ' << xhigh << '\n';
	return 0;
}