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

// include <= 1 of each item
int knapsack01(vector<int> &v, vector<int> &w, int cap) {
	int n = v.size();
	vector<int> dp(cap + 1);
	for (int i = 0; i < n; i++) {
		for (int j = cap; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[cap];
}

// include unlimited amount of each item
int knapsackComplete(vector<int> &v, vector<int> &w, int cap) {
	int n = v.size();
	vector<int> dp(cap + 1);
	for (int i = 0; i < n; i++) {
		for (int j = w[i]; j <= cap; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[cap];
}

// include <= avail[i] of each item
int knapsackMultiple(vector<int> &v, vector<int> &w, vector<int> &avail, int cap) {
	int n = v.size();
	int idx = 0;
	vector<int> dp(cap + 1);
	vector<int> newWeights, newValues;

	// store items corresponding to 1, 2, 4, ... , 2^floor(log avail[i]) of item i
	// to get from O(cap * sum of avail[i]) -> O(cap * sum of log(avail[i]))
	for(int i = 0; i < n; i++) {
		int pw = 1;
		while (avail[i] > pw) {
			avail[i] -= pw;
			newWeights[++idx] = pw * v[i];
			newValues[idx] = pw * w[i];
			pw <<= 1;
		}
		newWeights[++idx] = avail[i] * v[i];
		newValues[idx] = avail[i] * w[i];
	}
	return knapsack01(newValues, newWeights, cap);
}

// make partition equal to subarray sum
bool canPartition(vector<int> &nums) {
	int n = nums.size();
	int tot = accumulate(nums.begin(), nums.end(), 0);
	if (tot % 2) return false;
	tot /= 2;
	vector<int> dp(tot + 1);
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = tot; j >= nums[i]; j--) {
			dp[j] |= dp[j - nums[i]];
		}
	}
	return dp[tot];
}