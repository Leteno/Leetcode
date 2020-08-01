--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--

-- @lc code=start
select (
select distinct Salary
from Employee
order by Salary DESC
limit 1 offset 1)
as SecondHighestSalary;
-- @lc code=end

