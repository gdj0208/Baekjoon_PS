SELECT
  cus.country as country,
  SUM(price * quantity) as sales
FROM
  customers as cus
  INNER JOIN orders as ord ON cus.customer_id = ord.customer_id
  INNER JOIN order_items as ord_it ON ord.order_id = ord_it.order_id
WHERE
  order_date BETWEEN '2019-01-01' AND '2019-01-31' AND
  ord_it.order_id NOT LIKE 'c%'
GROUP BY
  cus.country
ORDER BY
  sales DESC