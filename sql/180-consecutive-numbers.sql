-- https://leetcode.com/problems/consecutive-numbers
-- Distinct needed as the window function returns a row for each instance of 3-pair of consecutive ids (i.e for 3+ consecutive cases)
SELECT DISTINCT ON(num) num AS ConsecutiveNums
FROM
    (-- Partitions by num ordered by id, then LAG takes the id of the row two (2) rows behind it; used to calc if consecutive ids
        SELECT num, id, (id - LAG(id, 2) OVER (PARTITION BY num ORDER BY id)) AS consecutive FROM Logs
    )
WHERE consecutive = 2
