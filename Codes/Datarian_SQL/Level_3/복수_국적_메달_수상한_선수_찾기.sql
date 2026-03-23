select ath.name
from athletes as ath
  left join records as rec on ath.id = rec.athlete_id
  left join teams on rec.team_id = teams.id
  left join games on games.id = rec.game_id
where games.year >= 2000 and rec.medal is not null
group by ath.id
having count(DISTINCT teams.team) >= 2
order by ath.name asc
