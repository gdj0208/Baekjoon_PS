WITH
  ranked_data as (
    SELECT
      *,
      DENSE_RANK() over(PARTITION BY day ORDER BY total_bill DESC) bill_rank
    FROM
      tips
  )
SELECT
  day,
  time,
  sex,
  total_bill
FROM
  ranked_data
WHERE
  bill_rank <= 3
order BY
  day