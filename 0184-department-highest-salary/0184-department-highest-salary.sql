# Write your MySQL query statement below
select d.name as "Department", e.name as "Employee", e.salary as Salary
from Employee e
join Department d on d.id=e.departmentId
where e.salary = (
    select max(e2.salary) from Employee e2
    where d.id=e2.departmentId
);