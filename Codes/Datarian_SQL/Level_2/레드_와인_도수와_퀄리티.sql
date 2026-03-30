SELECT *
FROM wines
WHERE quality >= 8
  and alcohol <= 12
  and color = 'red'
order by quality DESC, alcohol ASC