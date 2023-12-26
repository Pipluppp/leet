-- https://leetcode.com/problems/1193-monthly-transactions-i
SELECT month, country, COUNT(*) AS trans_count, SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
FROM (SELECT *, to_char(trans_date, 'YYYY-MM') AS month FROM Transactions)
GROUP BY country, month