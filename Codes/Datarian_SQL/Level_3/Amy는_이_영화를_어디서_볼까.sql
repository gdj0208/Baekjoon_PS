SELECT
  title,
  year,
  genres,
  directors,
  CASE
    WHEN(netflix = 1 and hulu = 0 and prime_video = 0 and disney_plus = 0) THEN 'netflix'
    WHEN(netflix = 0 and hulu = 1 and prime_video = 0 and disney_plus = 0) THEN 'hulu'
    WHEN(netflix = 0 and hulu = 0 and prime_video = 1 and disney_plus = 0) THEN 'prime_video'
    WHEN(netflix = 0 and hulu = 0 and prime_video = 0 and disney_plus = 1) THEN 'disney_plus'
    WHEN(netflix = 1) THEN 'netflix'
    WHEN(hulu = 1) THEN 'hulu'
    WHEN(prime_video = 1) THEN 'prime_video'
  END platform
FROM
  movies
WHERE 
  year >= 2021
ORDER BY
  title ASC