#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# @lc code=start
'''
  a        mid        b

mid = (a+b)/2 + 1  >>= a+1
1. target > a => (a+1 , max)
    1) target < mid => a  target mid  max  b
        => (a+1, mid)
    2) target > mid => 
        a     target  max min  mid    b
        a     mid    target max min b
        => (a+1, mid) || (mid, b)
        if mid > a:
            a mid target max min b
            (mid, b)
        else:
            a target max min mid b:
            (a+1, mid)
2. target < a => (min, b)
    1) target < mid
        => a  max min  target  mid  b
        => a  mid max min target b
        => (a+1, mid) || (mid, b)
        if mid > a:
            a mid max min target b
            (mid, b)
        else:
            a max min target mid b
            (a+1, mid)
    2) target > mid
        => a max min mid target b
        => (mid, b)
'''
def bSearch(nums, a, b, target):
    if a > b:
        return -1
    mid = (a + b + 1) // 2
    if target > nums[a]:
        if target < nums[mid]:
            return bSearch(nums, a+1, mid, target)
        elif target > nums[mid]:
            if nums[mid] > nums[a]:
                return bSearch(nums, mid, b, target)
            else:
                return bSearch(nums, a+1, mid, target)
        else:
            return mid
    elif target < nums[a]:
        if target < nums[mid]:
            if nums[mid] > nums[a]:
                return bSearch(nums, mid, b, target)
            else:
                return bSearch(nums, a+1, mid, target)
        elif target > nums[mid]:
            return bSearch(nums, mid, b, target)
        else:
            return mid
    else:
        return a

class Solution:
    def search(self, nums, target: int) -> int:
        return bSearch(nums, 0, len(nums)-1, target)

def myAssert(a, b):
    if a != b:
        print("expect: %s\ngot: %s" % (b, a))
    assert a == b

if __name__ == "__main__":
    myAssert(Solution().search([4,5,6,7,0,1,2], 0), 4)
    myAssert(Solution().search([4,5,6,7,0,1,2], 3), -1)
# @lc code=end

