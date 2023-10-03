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

ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res*= a;
			res%= m;
		}
		a*= a;
		a%= m;
		b>>= 1;
	}
	return res;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool isPrime(ll n) {
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, b;
	cin >> n >> b;
	int cur = n * (n + 1) / 2;
	int shift = 0;
	while (!isPrime(cur + shift)) {
		shift++;
	}
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	while (shift > 0) {
		for (int i = n - 1; shift > 0 && i >= 0; i--) {
			a[i]++;
			shift--;
		}
	}
	if (a[n - 1] > b) {
		cout << "impossible\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				cout << a[j + n - i] << ' ';
			}
			for (int j = i; j < n; j++) {
				cout << a[j - i] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}