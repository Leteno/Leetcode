#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
class Solution:
    def threeSum(self, nums):
        result = []
        newNums = sorted(nums)
        size = len(newNums)
        lastNum = None
        for i in range(size):
            if newNums[i] == lastNum:
                continue
            lastNum = newNums[i]
            target = -newNums[i]
            lo, hi = i + 1, size -1
            while lo < hi :
                loVal, hiVal = newNums[lo], newNums[hi]
                curSum = loVal + hiVal
                if curSum < target:
                    lo += 1
                elif curSum > target:
                    hi -= 1
                else :
                    result.append([newNums[i], loVal, hiVal])
                    while lo < hi and newNums[lo] == loVal:
                        lo += 1
                    while lo < hi and newNums[hi] == hiVal:
                        hi -= 1
        return result

# def myAssert(a, b):
#     if a != b:
#         print("expect: %s, got: %s" % (a, b))
#     assert(a == b)
# if __name__ == "__main__":
#     myAssert(Solution().threeSum([0,0,0,0]), [[0,0,0]])
#     myAssert(Solution().threeSum([-1, 0, 1, 2, -1, -4]), [[-1,-1,2], [-1,0,1]])
# @lc code=end

