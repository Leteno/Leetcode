#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#

# @lc code=start
class Solution:
    def threeSumClosest(self, nums, target: int) -> int:
        newNums = sorted(nums)
        length = len(newNums)
        maxSum = 10000
        lastDistance, closet = maxSum, None
        for i in range(length):
            curVal, lo, hi = newNums[i], i + 1, length - 1
            curTarget = target - curVal
            while lo < hi:
                distance = newNums[lo] + newNums[hi]  - curTarget
                absDistance = abs(distance)
                if absDistance < lastDistance:
                    lastDistance = absDistance
                    closet = newNums[lo] + newNums[hi] + curVal
                if distance > 0:
                    hi -= 1
                elif distance < 0:
                    lo += 1
                else:
                    return target
        return closet



# def myAssert(a, b):
#     if a != b:
#         print("expect: %s\ngot: %s\n" % (b, a))
#     assert(a == b)

# if __name__ == "__main__":
#     myAssert(Solution().threeSumClosest([-1, 2, 1, -4], 1), 2)
#     myAssert(Solution().threeSumClosest([-1, 2, 1, -4], 3), 2)
#     myAssert(Solution().threeSumClosest([-1, 2, 1, -4], -4), -4)
# @lc code=end

