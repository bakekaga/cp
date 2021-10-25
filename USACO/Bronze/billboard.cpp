#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	int lx1, ly1, lx2, ly2, cx1, cy1, cx2, cy2;
	cin >> lx1 >> ly1 >> lx2 >> ly2 >> cx1 >> cy1 >> cx2 >> cy2;
	if (ly1 >= cy1 && ly2 <= cy2 && lx1 >= cx1 && lx2 <= cx2) cout << 0 << '\n';

	else if (ly1 >= cy1 && ly2 <= cy2 && lx1 <= cx1 && lx2 <= cx2 && lx2 >= cx1) cout << (ly2 - ly1) * (cx1 - lx1) << '\n';
	else if (ly1 >= cy1 && ly2 <= cy2 && lx1 >= cx1 && lx2 >= cx2 && lx1 <= cx2) cout << (ly2 - ly1) * (lx2 - cx2) << '\n';

	else if (lx1 >= cx1 && lx2 <= cx2 && ly1 <= cy1 && ly2 <= cy2 && ly2 >= cy1) cout << (lx2 - lx1) * (cy1 - ly1) << '\n';
	else if (lx1 >= cx1 && lx2 <= cx2 && ly1 >= cy1 && ly2 >= cy2 && ly1 <= cy2) cout << (lx2 - lx1) * (ly2 - cy2) << '\n';

	else cout << (lx2 - lx1) * (ly2 - ly1) << '\n';
	return 0;
}