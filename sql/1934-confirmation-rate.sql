-- https://leetcode.com/problems/confirmation-rate
SELECT S.user_id, ROUND(AVG(CASE WHEN C.action = 'confirmed' THEN 1 ELSE 0 END), 2) AS
confirmation_rate
FROM Confirmations C
RIGHT JOIN Signups S ON C.user_id = S.user_id
GROUP BY S.user_id