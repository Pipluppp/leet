-- https://leetcode.com/problems/second-highest-salary

SELECT DISTINCT ON(salary) -- To have one representative for each salary/rank
    (-- Return null if no second highest
        CASE WHEN rank = 1 THEN NULL ELSE salary END
    ) AS SecondHighestSalary
FROM
( -- Ranks the salaries
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rank
    FROM Employee
)
-- Handles case when only a single salary rank (no second highest)
WHERE rank <= 2 -- Not sure why it automatically sorts from lowest to highest after this
LIMIT 1