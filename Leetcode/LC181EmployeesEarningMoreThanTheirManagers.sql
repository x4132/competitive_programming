SELECT e1.name as Employee FROM Employee e1 INNER JOIN Employee e2 ON e1.managerID = e2.id WHERE e1.salary > e2.salary;
