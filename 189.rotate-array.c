/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 */

// @lc code=start

void swap(int* nums, int start, int end) {
    int tmp;
    while (start < end) {
        tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start ++;
        end --;
    }
}

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    if (k == 0) return;
    swap(nums, 0, numsSize - k - 1);
    swap(nums, numsSize - k, numsSize - 1);
    swap(nums, 0, numsSize - 1);
}
// @lc code=end

