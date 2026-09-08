# Write your MySQL query statement below
SELECT e2.unique_id, e1.name
FROM EmployeeUNI as e2
RIGHT JOIN Employees as e1
ON e2.id=e1.id;