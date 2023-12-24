WITH employee_ranks AS
(
    SELECT 
        D.name AS Department,
        E.name AS Employee,
        E.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY E.departmentId ORDER BY E.salary DESC) AS rank
    FROM Employee E
    JOIN Department D ON E.departmentId = D.id
)

SELECT Department, Employee, Salary
FROM employee_ranks
WHERE rank <= 3