// MATH
#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 107
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

// GREATEST COMMON DIVISOR O(log n)

ll gcd_impl (ll n, ll m) {
    for (int i = 0; i < 10; ++i) {
        ll t = n - m;
        bool q = m > t;
        n = q ? m : t;
        m = q ? t : m;
        if (m == 0) return n;
    }
    return gcd_impl(m, n % m);
}
 
ll fast_gcd(ll n, ll m) {
    return (n > m) ? gcd_impl(n, m) : gcd_impl(m, n);
}

// LEAST COMMON MULTIPLE O(log n)

ll lcm(ll a, ll b) {
    return a * b / fast_gcd(a, b);
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

// PRIME FACTORIZATION O(sqrt n)

vector<pair<int,int>> pfact(int x) {
    vector<pair<int,int>> out;
    int count = 0;
    while (x % 2 == 0) {
        x/= 2;
        count++;
    }
    out.push_back(make_pair(2, count));
    for (int i = 3; i * i <= x; i+= 2) {
        if (x % i == 0) {
            count = 0;
            while (x % i == 0) {
                x/= i;
                count++;
            }
            out.push_back(make_pair(i, count));
        }
    }
    return out;
}

// EULER TOTIENT FUNCTION O(sqrt n)

int phi(int x) {
    vector<pair<int,int>> pfactor = pfact(x);
    int out = x;
    for (int i = 0; i < pfactor.size(); i++) {
        out/= pfactor[i].first;
        out*= pfactor[i].first - 1;
    }
    return out;
}

// DIVISOR COUNTING FUNCTION O(sqrt n)

int tau(int x) {
    vector<pair<int,int>> pfactor = pfact(x);
    int out = 1;
    for (int i = 0; i < pfactor.size(); i++) {
        out*= pfactor[i].second - 1;
    }
    return out;
}