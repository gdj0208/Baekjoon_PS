SELECT title
FROM film
WHERE title NOT LIKE '%A'
  AND title NOT LIKE '%E'
  AND title NOT LIKE '%I'
  AND title NOT LIKE '%O'
  AND title NOT LIKE '%U'
  AND (rating = 'NC-17' or rating = 'R')