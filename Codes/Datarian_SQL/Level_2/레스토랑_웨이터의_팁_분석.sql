SELECT 
  day, 
  time, 
  ROUND(avg(tip), 2) as avg_tip, 
  ROUND(avg(size), 2) as avg_size
FROM tips
GROUP BY day, time
ORDER BY day, time