class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back({nums[i], i});
        }
        sort(res.begin(), res.end());
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = res[l].first + res[r].first;
            if (sum == target) break;
            if (sum > target) --r;
            else ++l;
        }
        vector<int> ans{res[l].second, res[r].second};
        return ans;
    }
};