SELECT
  r1.order_date dt,
  count(DISTINCT r1.customer_id) as dau,
  count(DISTINCT r2.customer_id) as wau,
  round(count(DISTINCT r1.customer_id) / count(DISTINCT r2.customer_id), 2) stickiness
FROM
  records as r1
  left join records as r2 on r2.order_date BETWEEN DATE_SUB(r1.order_date, INTERVAL 6 DAY) and r1.order_date
where 
  r1.order_date BETWEEN '2020-11-01' and '2020-11-30'
GROUP BY
  r1.order_date