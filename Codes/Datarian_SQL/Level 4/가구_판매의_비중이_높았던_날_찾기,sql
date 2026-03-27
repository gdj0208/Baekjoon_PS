SELECT
  order_date,
  COUNT(
    DISTINCT case
      WHEN category = 'Furniture' THEN order_id
    END
  ) as furniture,
  ROUND(
    COUNT(
      DISTINCT case
        WHEN category = 'Furniture' THEN order_id
      END
    ) / COUNT(DISTINCT order_id) * 100,
    2
  ) as furniture_pct
FROM
  records
GROUP BY
  order_date
HAVING
  COUNT(DISTINCT order_id) >= 10
  and furniture_pct >= 40
ORDER BY
  furniture_pct DESC,
  order_date