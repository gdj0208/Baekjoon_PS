SELECT
  cus.id 
FROM
  customers as cus
  LEFT JOIN orders as ord on cus.id = ord.customer_id
WHERE 
  ord.id is NULL
ORDER BY
  cus.id ASC