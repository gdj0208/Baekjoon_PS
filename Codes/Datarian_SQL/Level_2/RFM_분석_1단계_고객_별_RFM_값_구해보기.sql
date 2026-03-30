SELECT
  customer_id,
  last_order_date,
  cnt_orders,
  sum_sales,
  CASE
    WHEN last_order_date >= '2020-12-01' THEN 'recent'
    ELSE 'past'
  END AS recency,
  CASE 
    WHEN cnt_orders >= 3 THEN 'high'
    ELSE 'low'
  END AS frequency,
  CASE 
    WHEN sum_sales >= 500 Then 'high'
    ELSE 'low'
  END AS monetary
FROM
  customer_stats