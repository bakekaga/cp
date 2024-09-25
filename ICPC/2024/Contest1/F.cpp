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
	int a = 0, b = 0;
	// by guessing 000...010...000 for i = 0 to 30 for both, we get the value at each index
	int globalRes;
	printf("? 0 0\n");
	fflush(stdout);
	scanf("%d", globalRes);
	for (int i = 29; i >= 0; i++) {
		printf("? %d %d\n", (a + (1 << i)), (b + (1 << i)));
		fflush(stdout);
		int res;
		scanf("%d", res);
		if (res == 1) {
			printf("? %d 0\n", (1 << i));
			fflush(stdout);
			scanf("%d", res);
			if (res == -1) {
				a += (1 << i);
			}
		}
		else if (res == -1) {
			printf("? %d 0\n", (1 << i));
			fflush(stdout);
			scanf("%d", res);
			if (res == 1) {
				a += (1 << i);
				b += (1 << i);
			}
		}
		else {
			printf("? %d 0\n", (1 << i));
			fflush(stdout);
			scanf("%d", res);
			if (res == -1) {
				a += (1 << i);
				b += (1 << i);
			}
		}
	}
	return 0;
}