-- https://leetcode.com/problems/monthly-transactions-i
SELECT month, country, COUNT(*) AS trans_count,
    -- Used FILTER instead of cases
    COUNT(*) FILTER (WHERE state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    -- Needs COALESCE to turn NULL (when no row passes FILTER) into 0
    COALESCE(SUM(amount) FILTER (WHERE state = 'approved'), 0) AS approved_total_amount
FROM (SELECT *, to_char(trans_date, 'YYYY-MM') AS month FROM Transactions)
GROUP BY country, month