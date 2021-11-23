#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define sz(x) (int) (x).size() 
#define pb push_back

using namespace std;

int main() {
    ll k, x, y, z, n;

    // bit masks
    x |= (1LL<<k); // changes kth bit to 1
    x &= ~(1LL<<k); // changes kth bit to 0
    x ^= (1LL<<k); // inverts kth bit
    
    cout << (x & (x - 1)) << '\n'; // is 0 when x is power of 2
    cout << __builtin_clz(x) << '\n'; // # of leading 0s
    cout << __builtin_ctz(x) << '\n'; // # of ending 0s (largest power of 2 dividing x)
    cout << __builtin_popcount(x) << '\n'; // # of 1s
    cout << __builtin_parity(x) << '\n'; // parity of # of 1s (1 odd 0 even)

    // set operations
    x = (1<<1) | (1<<3) | (1<<4) | (1<<8); // x represents set {1, 3, 4, 8}
    y = (1<<3) | (1<<6) | (1<<8) | (1<<9); // y represents set {3, 6, 8, 9}

    z = x | y; // z is union of x, y
    z = x & y; // z is intersection of x, y
    z = ~x; // z is complement of x (universal set is {1, 2, ... , 64})
    z = x & (~y); // z is set difference of x, y

    // process subsets of {1, 2, ... , n} in order of {}, {1}, {2}, {1, 2}, {3}, {1, 3}, ...
    for (int b = 0; b < (1<<n); b++) {
        if (__builtin_popcount(b) == k) { // processes subsets of size k

        }
    }

}