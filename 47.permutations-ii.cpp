/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permuteUniqueInternal(nums, 0, result);
        return result;
    }
    void permuteUniqueInternal(vector<int>& nums, int cur, vector<vector<int>>& result) {
        if (cur == nums.size()-1) {
            result.push_back(nums);
            return;
        }

        /**
         * permute(a, b, c, d)
         * => {a}+permute(b, c, d)
         *    {b}+permute(a, c, d)
         *    {c}+permute(a, b, d)
         *    {d}+permute(a, b, c)
         * 
         * when duplicate:
         * permute(a, b, c, a)
         * => {a}+permute(b, c, a)
         *    {b}+permute(a, c, a)
         *    {c}+permute(a, b, a)
         *    {a}+permute(a, b, c) // this is what we want to avoid
         * 
         * Sorted array is a good way to avoid in the first time.
         * However, as the length longer, swap times grow, it cannot
         * guarant it.
         * 
         * A set would help us, though it cause much...
         **/
        set<int> occurs;
        for (int i = cur; i < nums.size(); ++i) {
            if (occurs.find(nums[i]) != occurs.end()) {
                continue;
            }
            occurs.insert(nums[i]);
            swap(nums[i], nums[cur]);
            permuteUniqueInternal(nums, cur+1, result);
            swap(nums[cur], nums[i]);
        }
    }
};
// @lc code=end

