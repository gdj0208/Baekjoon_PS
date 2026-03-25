with
  mentee as (
    select
      employee_id as mentee_id,
      name as mentee_name,
      department as mentee_dep
    from
      employees
    where
      join_date BETWEEN '2021-09-30' and '2021-12-31'
  ),
  mentor as (
    select
      employee_id as mentor_id,
      name as mentor_name,
      department as mentor_dep
    from
      employees
    where
      join_date <= '2019-12-31'
  ),
  pair as (
    select
      *
    from
      mentee
      join mentor
    where
      mentee_dep != mentor_dep
  )
select
  mentee_id, mentee_name, mentor_id, mentor_name
from
  pair
order by
  mentee_id ASC,
  mentor_id ASC
limit
  50