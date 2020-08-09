/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteInternal(nums, 0, result);
        return result;
    }
    void permuteInternal(vector<int>& nums, int cur, vector<vector<int>>& result) {
        if (cur == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); ++i) {
            swap(nums[cur], nums[i]);
            permuteInternal(nums, cur+1, result);
            swap(nums[cur], nums[i]);
        }
    }
};
// @lc code=end

