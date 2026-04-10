SELECT bike_id
FROM rental_history
WHERE DATE(rent_at) BETWEEN '2021-01-01' AND '2021-02-01'
GROUP BY bike_id
HAVING SUM(distance) >= 50000