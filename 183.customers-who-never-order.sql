--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- @lc code=start
# Write your MySQL query statement below
SELECT m.Name as Customers
from (select c.Id, c.Name, o.Id as OrderId from Customers as c left join Orders as o
    On c.Id = o.CustomerId) as m
where ISNULL(m.OrderId);
-- @lc code=end

