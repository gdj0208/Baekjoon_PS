SELECT
  SUM(price * (-quantity)) AS 'refund_austria'
FROM
  customers as cus
  INNER JOIN orders as ord ON cus.customer_id = ord.customer_id
  INNER JOIN order_items as ord_it ON ord.order_id = ord_it.order_id
WHERE
  cus.country = 'Austria' AND
  ord_it.quantity < 0