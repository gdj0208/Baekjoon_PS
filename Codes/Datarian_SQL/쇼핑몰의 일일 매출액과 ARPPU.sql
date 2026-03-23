select 
  date(data.order_purchase_timestamp) as dt,
  count(DISTINCT data.customer_id) as pu,
  round(sum(pay.payment_value), 2) as revenue_daily,
  round(sum(pay.payment_value)/count(DISTINCT data.customer_id), 2) as arppu
from olist_orders_dataset as data
  left join olist_order_payments_dataset as pay
  on data.order_id = pay.order_id
where data.order_purchase_timestamp >= '2018-01-01'
group by date(data.order_purchase_timestamp)
order by dt ASC