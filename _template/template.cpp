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

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

// FILE I/O

void setIO(string prob = "") {
	if (sz(prob)) {
		freopen((prob + ".in").c_str(), "r", stdin);
		freopen((prob + ".out").c_str(), "w", stdout);
	}
}

// READ IN STRING LINES O(n)

void readin() {
	string in;
	getline(cin, in);
}

// READ IN INTEGERS FROM STRING O(n)

void readin() {
	string in;
	getline(cin, in);
	stringstream ss;
	ss << in;
	string temp;
	ll num;
	vector<ll> nums;
	while (!ss.eof()) {
		ss >> temp; 
		stringstream sss;
		sss << temp;
		sss >> num; nums.pb(num);
		temp = "";
	}
}

// STRING UPPER/LOWERCASE

string to_upper(string a) {
	for (int i = 0; i < sz(a); i++) if (a[i] >= 'a' && a[i] <= 'z') a[i]-= 'a' - 'A';
	return a;
}
 
string to_lower(string a) {
	for (int i = 0 ; i < sz(a); i++) if (a[i] >= 'A' && a[i] <= 'Z') a[i]+= 'a' - 'A';
	return a;
}

// FLOOR(A / B)

ll floordiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b);}

// BINARY SEARCH OVER INTEGERS O(log n)

// monotonic checker function

bool ok(int x) {
	return false;
}

// bsearch function for largest x satisfying ok(x) on (lo, hi]

ll bsearch() {
	ll out = -1;
	for (ll bb = MAXN; bb >= 1; bb /= 2) {
		while (!ok(out + bb)) out+= bb;
	}
	return out;
}

ll bsearch() {
	ll lo = 0, hi = MAXN;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (!ok(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	return lo;
}

// ORDERED SET (same as set, but with index finding)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace __gnu_pbds;

void examples() {
	ordered_set o;
	int val = 1;
	o.insert(val);

	// find # of elements strictly smaller than val (so its index)
	o.order_of_key(val);

	// find 0th element, with zero indexing
	o.find_by_order(0);
}

// // TRIM VECTOR OF DUPLICATES

// v.erase(unique(v.begin(), v.end()), v.end());

// MAX SUBARRAY SUM (KADANE ALGORITHM) O(n)

// if empty subarray is not allowed (answer can be negative):

ll kadane(int n) {
	vector<ll> arr(n);
	ll best = INT_MIN, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(arr[k], sum + arr[k]);
		best = max(best, sum);
	}
	return best;
}

// if empty subarray is allowed (answer must be nonnegative):

ll kadane(int n) {
	vector<ll> arr(n);
	ll best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(0LL, sum + arr[k]);
		best = max(best, sum);
	}
	return best;
}

// FIND MEX (minimum excluded element) OF ARRAY O(n)

int mex(int n) {
	vector<int> arr(n);
	vector<int> vis(n + 1);
	int mex = 0;
	for (int i = 0; i < n; i++) {
		vis[arr[i]]++;
		while (vis[mex]) mex++;
	}
}