SELECT
  DATE(order_purchase_timestamp) as purchase_date,
  COUNT(
    case
      when order_estimated_delivery_date >= order_delivered_customer_date THEN order_id
    END
  ) as success,
  COUNT(
    case
      when order_estimated_delivery_date < order_delivered_customer_date THEN order_id
    END
  ) as fail
FROM
  olist_orders_dataset
WHERE 
  DATE(order_purchase_timestamp) BETWEEN '2017-01-01' AND '2017-01-31' AND
  order_delivered_customer_date is not NULL AND
  order_estimated_delivery_date is not NULL
GROUP BY
  DATE(order_purchase_timestamp)
order BY
  DATE(order_purchase_timestamp)