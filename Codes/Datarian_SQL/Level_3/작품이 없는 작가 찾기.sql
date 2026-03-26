WITH dead_artists as (
  SELECT *
  FROM artists
  WHERE death_year is not NULL
)

SELECT artist_id, name
FROM dead_artists
WHERE artist_id not in (SELECT artist_id FROM artworks_artists)