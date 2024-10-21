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
	vector<string> sched(7);
	vector<int> bitReps(7);
	for (int i = 0; i < 7; i++) {
		cin >> sched[i];
		for (int j = 0; j < 24; j++) {
			if (sched[i][j] == '.')
				bitReps[i] |= (1 << j);
		}
	}
	int d, h;
	cin >> d >> h;
	int out = 0;
	for (unsigned int s = 0; s < (1 << 7); s++) {
		if (__builtin_popcount(s) == d) {
			vector<int> incl;
			priority_queue<int> best;
			for (int i = 0; i < 7; i++) {
				if (s & (1 << i)) {
					incl.push_back(i);
				}
			}
			for (int i = 0; i < 24; i++) {
				int hourTot = 0;
				for (int j : incl) { // each index included
					if (bitReps[j] & (1 << i)) hourTot++;
				}
				best.push(hourTot);
			}
			int tot = 0;
			for (int i = 0; i < h; i++) {
				tot += best.top();
				best.pop();
			}
			out = max(out, tot);
		}
	}
	cout << (out + 0.0) / (h * d) << '\n';
	return 0;
}