SELECT
  DATE_FORMAT(cus.first_order_date, '%Y-%m-01') first_order_month,
  count(distinct case when DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month0,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 1 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month1,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 2 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month2,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 3 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month3,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 4 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month4,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 5 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month5,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 6 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month6,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 7 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month7,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 8 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month8,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 9 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month9,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 10 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month10,
  count(distinct case when DATE_ADD(DATE_FORMAT(cus.first_order_date, '%Y-%m-01'), INTERVAL 11 MONTH) = DATE_FORMAT(rec.order_date, '%Y-%m-01') then rec.customer_id end) month11
FROM
  records as rec
  left join customer_stats as cus on rec.customer_id = cus.customer_id
GROUP BY
  DATE_FORMAT(cus.first_order_date, '%Y-%m-01')