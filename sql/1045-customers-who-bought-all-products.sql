SELECT customer_id
FROM (SELECT DISTINCT * FROM Customer)
GROUP BY customer_id
HAVING COUNT(*) = (SELECT COUNT(*) FROM Product)