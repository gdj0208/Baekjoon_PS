SELECT DISTINCT(records.athlete_id)
FROM events
  LEFT JOIN records on events.id = records.event_id
where sport like'Golf'