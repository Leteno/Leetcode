#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start

class Stack:
    def __init__(self):
        self.stack = []
        self.index = 0

    def push(self, x):
        if self.index < len(self.stack):
            self.stack.insert(self.index, x)
        else:
            self.stack.append(x)
        self.index += 1

    def pop(self):
        self.index -= 1

    def top(self):
        if self.index > 0:
            return self.stack[self.index - 1]
        return None

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.raw = Stack()
        self.min = Stack()

    def push(self, x: int) -> None:
        self.raw.push(x)
        curMin = self.min.top()
        if curMin is None or x < curMin:
            self.min.push(x)
        else:
            self.min.push(curMin)

    def pop(self) -> None:
        self.raw.pop()
        self.min.pop()
        

    def top(self) -> int:
        return self.raw.top()
        

    def getMin(self) -> int:
        return self.min.top()
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

