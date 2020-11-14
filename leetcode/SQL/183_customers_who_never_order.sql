# Write your MySQL query statement below
select Name as 'Customers' from Customers C 
left join Orders O
on C.Id = O.CustomerId
where O.CustomerId is null