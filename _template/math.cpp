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

// GREATEST COMMON DIVISOR O(log n)

ll gcd(ll n, ll m) {
    if (n < m) swap(n, m);
    for (int i = 0; i < 10; ++i) {
        ll t = n - m;
        bool q = m > t;
        n = q ? m : t;
        m = q ? t : m;
        if (m == 0) return n;
    }
    return gcd(m, n % m);
}

// LEAST COMMON MULTIPLE O(log n)

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

// BINARY EXPONENTIATION

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res*= a;
        }
        a*= a;
        b >>= 1;
    }
    return res;
}

// BINARY EXPONENTIATION WITH MOD

ll binpow(ll a, ll b, ll m) {
    a %= m;
// IF m IS PRIME
//     b %= (m - 1);
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

// POLYNOMIAL MULTIPLICATION O(n)

vector<ll> polymult(vector<ll> poly1, vector<ll> poly2) {
    vector<ll> prod(poly1.size() + poly2.size() - 1);
    for (int i = 0; i < poly1.size(); i++) {
        for (int j = 0; j < poly2.size(); j++) {
            prod[i+j]+= poly1[i] * poly2[j];
        }
    }
}

// ITERATING THROUGH ALL 2-COLORINGS OF A SET O(n2^n)

void twocolor(int n) {
    for (int i = 0; i < (1 << n); i++) {
        set<int> a, b;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) a.insert(j + 1);
            else b.insert(j + 1);
        }
    }
}

// MILLER-RABIN PRIMALITY TEST O(log n)

bool isPrime(uint64_t n) {
    if (n < 2) return false;
    
    int s = 0;
    uint64_t d = n - 1;
    while (!(d & 1)) {
        d>>= 1;
        s++;
    }
    // int s = __builtin_ctzll(n - 1);
    // uint_64_t d = n >> s;

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {        
        uint64_t x = binpow(a % n, d, n);
        if (x == 1 || !(a % n)) continue;
        int cnt = s;
        while (cnt-- && x != n - 1) {
            x = (__uint128_t) x * x % n;
        }
        if (cnt == 0) return false;
    }
    return true;
}