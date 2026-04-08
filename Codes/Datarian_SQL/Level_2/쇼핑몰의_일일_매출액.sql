SELECT 
  DATE(order_purchase_timestamp) AS dt,
  ROUND(SUM(payment_value), 2) as revenue_daily
FROM olist_orders_dataset as ord
  LEFT JOIN olist_order_payments_dataset as pay
    ON ord.order_id = pay.order_id
WHERE DATE(order_purchase_timestamp) >= '2018=01-01'
GROUP BY DATE(order_purchase_timestamp)
ORDER BY dt