SELECT
  emp.employee_id,
  emp.name,
  emp.manager_id,
  mana.name as manager_name
FROM
  employees as emp
  LEFT JOIN employees as mana on emp.manager_id = mana.employee_id
WHERE
  emp.manager_id is not NULL
ORDER BY
  emp.employee_id ASC