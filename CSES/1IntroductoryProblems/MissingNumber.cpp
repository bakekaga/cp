#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(); ios::sync_with_stdio(0);
    int n; cin >> n;
    ll arr[n - 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n - 1);
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << i + 1; break;
        }
    }
    return 0;
}
