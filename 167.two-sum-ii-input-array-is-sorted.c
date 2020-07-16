/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    int lIndex = 0, rIndex = numbersSize - 1;
    int sum;
    while (lIndex != rIndex) {
        sum = numbers[lIndex] + numbers[rIndex];
        if (sum < target) {
            ++lIndex;
        } else if (sum > target) {
            --rIndex;
        } else {
            break;
        }
    }

    result[0] = lIndex + 1;
    result[1] = rIndex + 1;
    return result;
}
// @lc code=end

