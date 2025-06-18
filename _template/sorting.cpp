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

// MERGE SORT O(n log n)

void merge(vector<int> &a, int start, int end) {
	vector<int> out(end - start + 1);
	int mid = start + (end - start) / 2;
	int i = start, j = mid + 1;
	for (int k = 0; k < out.size(); k++) {
		if (i <= mid && (j > end || a[i] < a[j])) {
			out[k] = a[i++];
		}
		else {
			out[k] = a[j++];
		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = out[i - start];
	}
}

void mergeSort(vector<int> &a, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = start + (end - start) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);
	merge(a, start, end);
}

// COUNT SORT O(n), REQUIRES SMALL RANGE OF ARRAY VALUES

void countSort(vector<int> &a, int minN, int maxN) {
	vector<int> freq(maxN - minN + 1);
	for (int i = 0; i < a.size(); i++) {
		freq[a[i] - minN]++; 
	}
	for (int i = 0, j = 0; i < freq.size(); i++) {
		while (freq[i]) {
			freq[i]--;
			a[j] = i + minN;
			j++;
		}
	}
}
