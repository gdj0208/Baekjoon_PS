SELECT
  day,
  SUM(tip) as tip_daily,
  SUM(total_bill) as revenue_daily,
  ROUND(SUM(tip) / SUM(total_bill) * 100, 2) as tip_revenue_pct
FROM
  tips
GROUP BY
  day
ORDER BY
  ROUND(SUM(tip) / SUM(total_bill) * 100, 2) DESC
