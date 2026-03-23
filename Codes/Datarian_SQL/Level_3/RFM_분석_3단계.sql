SELECT
  CASE 
    WHEN last_order_date >= '2020-12-01' THEN 'recent'
    ELSE 'past'
  END AS recency,
  CASE 
    WHEN cnt_orders >= 3 THEN 'high'
    ELSE 'low'
  END AS frequency,
  CASE 
    WHEN sum_sales >= 500 THEN 'high'
    ELSE 'low'
  END AS monetary,
  COUNT(DISTINCT customer_id) AS customers
FROM
  customer_stats
GROUP BY
  recency, frequency, monetary
HAVING
  frequency = 'high' AND monetary = 'high'
ORDER BY
  recency DESC
