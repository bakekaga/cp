#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

template<class T> bool ckmin(T &a, const T &b) { return b<a?a=b,1:0; }
template<class T> bool ckmax(T &a, const T &b) { return b>a?a=b,1:0; }

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

// MOD OPERATIONS, .v RETURNS VALUE

struct mi {
    int v; explicit operator int() const { return v; }
    mi(ll _v) : v(_v%MOD) { v += (v<0)*MOD; }
    mi() : mi(0) {}
};
mi operator+(mi a, mi b) { return mi(a.v+b.v); }
mi operator-(mi a, mi b) { return mi(a.v-b.v); }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }

// READ IN STRINGS O(n)

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

// bsearch function for smallest x satisfying ok(x) on (lo, hi]

ll bsearch() {
    ll out = MAXN;
    for (ll bb = MAXN; bb >= 1; bb /= 2) {
        while (!ok(out - bb)) out-= bb;
    }
    return out;
}

ll bsearch() {
    int lo, hi;
    while (lo <= hi - 1) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid;
    }
    return hi;
}

int bsearch(int x, vector<int> &a) {
    int lo = 1, hi = MAXN;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (x < a[mid]) hi = mid - 1;
        else if (x > a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

// BINARY SEARCH OVER SEARCH ARRAY O(log n)

// lower_bound(arr, arr + n, val) returns iterator to 
// smallest index of arr with element at least val

// upper_bound(arr, arr + n, val) returns iterator to
// largest index of arr with element at most val

// BINARY SEARCH FOR OVER SET O(log n)

// s.lower_bound(val) returns iterator to smallest index
// of arr with element at least val

// s.upper_bound(val) returns iterator to largest index
// of arr with element at most val

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