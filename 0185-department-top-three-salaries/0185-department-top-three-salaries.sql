select Department,Employee,Salary from (
    select d.name as 'Department',e.name as 'Employee',e.salary as 'Salary',dense_rank() over (
    partition by d.id
    order by e.salary desc
    ) as d_rank
    from Employee e
    join Department d on e.departmentId=d.id
) t
where t.d_rank<=3
order by t.Department,t.Salary desc;