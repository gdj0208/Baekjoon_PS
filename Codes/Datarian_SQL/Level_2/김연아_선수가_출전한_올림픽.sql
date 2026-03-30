SELECT
  games.year as year,
  games.season as season,
  games.city as city
FROM
  records
  INNER JOIN games on records.game_id = games.id
  INNER JOIN athletes on records.athlete_id = athletes.id
WHERE
  athletes.name = 'Yu-Na Kim'
ORDER BY
  year DESC