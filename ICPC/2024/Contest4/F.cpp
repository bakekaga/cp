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
	int x1, y1, x2, y2, a;
	cin >> x1 >> y1 >> x2 >> y2 >> a;
	double xmax = 0.5 * (x1 + x2 + sqrt(a * a - (y2 - y1) * (y2 - y1)));
	double ymax = 0.5 * (y1 + y2 + sqrt(a * a - (x2 - x1) * (x2 - x1)));
	double xmin = x1 + x2 - xmax;
	double ymin = y1 + y2 - ymax;
	cout << fixed << setprecision(5) << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << '\n';
	return 0;
}