#include <bits/stdc++.h>

#define MOD 10000007
#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        if (n % 2 == 0) {  
            for (int i = 1; i <= n / 2; i++) cout << (2 * i) << " ";
            for (int i = 1; i <= n / 2; i++) cout << (2 * i - 1) << " ";
        }
        else {
            for (int i = 1; i <= (n - 1) / 2; i++) cout << (2 * i) << " ";
            for (int i = 0; i <= (n - 1) / 2; i++) cout << (2 * i + 1) << " ";
        }
    }
    return 0;
}