#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start


class Solution:
    def combinationSum(self, candidates, target: int):
        result = []
        def combinationSub(candidates, target, stack, begin, size):
            if target == 0:
                result.append(stack[:])
                return
            for i in range(begin, size):
                if target >= candidates[i]:
                    stack.append(candidates[i])
                    combinationSub(candidates, target - candidates[i], stack, i, size)
                    stack.pop()

        combinationSub(candidates, target, [], 0, len(candidates))
        return result

def myAssert(a, b):
    if a != b:
        print("expected: %s\ngot: %s" % (b, a))
    assert a == b

if __name__ == "__main__":
    myAssert(Solution().combinationSum([2,3,6,7], 7), [[2,2,3], [7]])
    myAssert(Solution().combinationSum([2,3,5], 8), [[2,2,2,2], [2,3,3], [3,5]])

# @lc code=end

