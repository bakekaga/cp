#include <bits/stdc++.h>
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const array<int, 4> dx = {0, -1, 0, 1};
const array<int, 4> dy = {-1, 0, 1, 0};

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

#include <stdio.h>
// file I/O
FILE *freopen(const char *pathname, const char *mode, FILE *stream);
int fscanf(FILE *stream, const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
// string input
char *fgets(char *s, int size, FILE *stream);
// byte I/O (depends on if machine is big or little endian)
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int fflush(FILE *stream);

// SET OUTPUT PRECISION

#include <iomanip>
void setprec() {
	cout << fixed << setprecision(10) << acos(-1) << '\n';
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

vector<string> split(string s, char delim) {
	size_t pos = s.find(delim, 0);
	vector<string> tokens;
	while (pos != string::npos) {
		string token = s.substr(0, pos);
		tokens.push_back(token);
		s = s.substr(pos + 1);
		pos = s.find(delim, 0);
	}
	tokens.push_back(s);
	return tokens;
}

// STRING UPPER/LOWERCASE (there exists std library toupper/tolower for chars lol)

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

// bsearch function for largest x satisfying ok(x) on [lo, hi]

ll bsearch() {
	ll out = -1;
	for (ll bb = MAXN; bb >= 1; bb /= 2) {
		while (!ok(out + bb)) out+= bb;
	}
	return out;
}

int bsearch(int l, int r) {
	int lo = l, hi = r;
	// if r unknown
	hi = 1;
	while (ok(r)) {
		r <<= 1;
	}
	// if l, r are real, just do for fixed # of iterations (100 good enough)
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (!ok(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}

// ORDERED SET (same as set, but with index finding)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T = int> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void examples() {
	ordered_set o;
	int val = 1;
	o.insert(val);

	// find # of elements strictly smaller than val (so its index)
	o.order_of_key(val);

	// find 0th element, with zero indexing
	o.find_by_order(0);
}

// TRIM VECTOR OF DUPLICATES

// v.erase(unique(v.begin(), v.end()), v.end());

// FIND MEX (minimum excluded element) OF ARRAY O(n)

int mex(int n) {
	vector<int> arr(n);
	vector<int> vis(n + 1);
	int mex = 0;
	for (int i = 0; i < n; i++) {
		vis[arr[i]]++;
		while (vis[mex]) mex++;
	}
	return mex;
}

// TIME

void time () {
	auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	// insert awesome algorithm here
	auto stop = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	cerr << "Took " << stop - start << "ms\n";
}