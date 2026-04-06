SELECT 
  DATE(order_delivered_carrier_date) as delivered_carrier_date,
  COUNT(CASE WHEN order_delivered_customer_date IS NULL THEN 1 END) AS orders
FROM olist_orders_dataset
WHERE order_delivered_carrier_date BETWEEN '2017-01-01' AND '2017-02-01'
GROUP BY delivered_carrier_date
HAVING orders != 0
ORDER BY delivered_carrier_date