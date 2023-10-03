#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int LGN = 30;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
// void __print(mi x) {cerr << x;}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << ((n & 1) ? "N\n" : "A\n");
	}
	else if (k == 2) {
		cout << ((n & 1) ? "A\n" : "N\n");
	}
	else {
		vector<ll> fibb;
		fibb.pb(0);
		fibb.pb(1);
		for (int i = 2; i <= n; i++) {
			fibb.pb(fibb[i - 2] + fibb[i - 1]);
			if (fibb[i] > k) {
				n = sz(fibb);
				break;
			}
		}
		while (n > 2) {
			if (k > fibb[n - 2]) {
				k -= fibb[n - 2];
				n--;
			}
			else {
				n -= 2;
			}
		}
		cout << (n == 1 ? "N\n" : "A\n");
	}
}