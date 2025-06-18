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

void backtrackDuplicateSubsets(int i, vector<int> &cur, vector<int> &nums, vector<vector<int>> &res) {
	if (i == sz(nums))
		res.pb(cur);
		return;
	cur.pb(nums[i]);
	backtrackDuplicateSubsets(i, cur, nums, res);
	cur.pop_back();
	backtrackDuplicateSubsets(i + 1, cur, nums, res);
}

vector<vector<int>> duplicateSubsets(vector<int> &nums) {
	vector<vector<int>> res;
	vector<int> cur;
    backtrackDuplicateSubsets(0, cur, nums, res);
    return res;
}

void backtrackDistinctSubsets(int i, vector<int> &cur, vector<int> &nums, vector<vector<int>> &res) {
	if (i == sz(nums))
		res.pb(cur);
		return;
	cur.pb(nums[i]);
	backtrackDistinctSubsets(i + 1, cur, nums, res);
	cur.pop_back();
	while (i + 1 < sz(nums) && nums[i] == nums[i + 1]) {
		i++;
	}
	backtrackDistinctSubsets(i + 1, cur, nums, res);
}

vector<vector<int>> distinctSubsets(vector<int> &nums) {
	vector<vector<int>> res;
    sort(nums.begin(), nums.end());
	vector<int> cur;
    backtrackDistinctSubsets(0, cur, nums, res);
    return res;
}

void backtrackPerm(vector<bool> &chosen, vector<int> &cur, vector<int> &nums, vector<vector<int>> &res) {
	if (sz(cur) == sz(nums))
		res.pb(cur);
		return;
	for (int i = 0; i < sz(nums); i++) {
		if (chosen[i]) continue;
		cur.pb(nums[i]);
		chosen[i] = true;
		backtrackPerm(chosen, cur, nums, res);
		cur.pop_back();
		chosen[i] = false;
	}
}

vector<vector<int>> permutations(vector<int> &nums) {
	vector<vector<int>> res;
	vector<int> cur;
	vector<bool> chosen;
    backtrackPerm(chosen, cur, nums, res);
    return res;
}
