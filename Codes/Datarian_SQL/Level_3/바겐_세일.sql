SELECT
  order_date,
  SUM(
    CASE 
      WHEN discount >= 0.8 THEN quantity
      ELSE 0
    END
  ) AS big_discount_items,
  SUM(quantity) AS all_items
FROM 
  records
GROUP BY
  order_date
HAVING
  big_discount_items >= 1 AND
  all_items >= 10
ORDER BY
  big_discount_items DESC