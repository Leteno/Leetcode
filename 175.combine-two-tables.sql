--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
select p.FirstName as FirstName, p.LastName as LastName, a.City as City, a.State as State
from Person as p left join Address as a
On p.PersonId = a.PersonId;
-- @lc code=end

