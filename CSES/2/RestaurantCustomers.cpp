#include <bits/stdc++.h>
#define mp make_pair
#define MAXN 2000000
#define pb push_back
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
    	cin.tie(0);
	int n, a, b, num = 0, maxn = 0;
	cin >> n;
	vector<pair<int,int>> c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		c.pb(mp(a,1));
		c.pb(mp(b,-1));
	}
	sort(c.begin(), c.end());
	for (auto x : c) {
		num+= x.second;
		maxn = max(num,maxn);
	}
	cout << maxn << '\n';
	return 0;
}