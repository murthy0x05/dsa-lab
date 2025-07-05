SELECT d.name Department, e.name Employee, e.salary Salary
FROM Employee e
INNER JOIN Department d
ON e.departmentId = d.id
WHERE (e.salary, e.departmentId) IN (
    SELECT MAX(salary), departmentId
    FROM Employee
    GROUP BY departmentId
)