SELECT 
  species,
  ROUND(
    (
      COUNT(*) * SUM(flipper_length_mm * body_mass_g) - SUM(flipper_length_mm) * SUM(body_mass_g)
    ) 
    / 
    NULLIF(
      SQRT(
        (COUNT(*) * SUM(flipper_length_mm * flipper_length_mm) - POW(SUM(flipper_length_mm), 2)) 
        * (COUNT(*) * SUM(body_mass_g * body_mass_g) - POW(SUM(body_mass_g), 2))
      ), 0
    )
  , 3) AS corr
FROM penguins
WHERE flipper_length_mm IS NOT NULL 
  AND body_mass_g IS NOT NULL
GROUP BY species