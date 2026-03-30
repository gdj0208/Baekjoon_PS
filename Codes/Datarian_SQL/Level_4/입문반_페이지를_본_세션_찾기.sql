WITH  
  total as (
    SELECT
      user_pseudo_id,
      ga_session_id
    FROM
      ga
  ),
  pv_no as (
    SELECT
      user_pseudo_id,
      ga_session_id
    FROM
      ga
    WHERE
      page_title = '백문이불여일타 SQL 캠프 입문반' AND
      event_name = 'page_view'
  )
SELECT
  count(DISTINCT total.user_pseudo_id, total.ga_session_id) as total,
  count(DISTINCT total.user_pseudo_id, total.ga_session_id) - count(DISTINCT pv_no.user_pseudo_id, pv_no.ga_session_id) pv_no,
  count(DISTINCT pv_no.user_pseudo_id, pv_no.ga_session_id) as pv_yes
FROM
  total
  left join pv_no on total.user_pseudo_id = pv_no.user_pseudo_id and total.ga_session_id = pv_no.ga_session_id
limit 1000