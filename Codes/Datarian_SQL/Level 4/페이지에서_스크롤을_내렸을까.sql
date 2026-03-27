WITH
  total as (
    SELECT
      user_pseudo_id,
      ga_session_id,
      event_timestamp_kst time
    FROM
      ga
  ),
  pv_yes as (
    SELECT
      user_pseudo_id,
      ga_session_id,
      event_timestamp_kst time
    FROM
      ga
    WHERE
      page_title = '백문이불여일타 SQL 캠프 입문반' and
      event_name = 'page_view'
  ),
  scroll as (
    SELECT
      user_pseudo_id,
      ga_session_id,
      event_timestamp_kst time
    FROM
      ga
    WHERE
      page_title = '백문이불여일타 SQL 캠프 입문반' and
      event_name = 'scroll'
  )
SELECT
  count(DISTINCT total.user_pseudo_id, total.ga_session_id) total,
  count(DISTINCT total.user_pseudo_id, total.ga_session_id)-count(DISTINCT pv_yes.user_pseudo_id, pv_yes.ga_session_id) pv_no,
  count(DISTINCT pv_yes.user_pseudo_id, pv_yes.ga_session_id) - count(DISTINCT scroll.user_pseudo_id, scroll.ga_session_id) pv_yes_scroll_no,
  count(DISTINCT scroll.user_pseudo_id, scroll.ga_session_id) pv_yes_scroll_yes
FROM
  total
  LEFT JOIN pv_yes on total.user_pseudo_id = pv_yes.user_pseudo_id and total.ga_session_id = pv_yes.ga_session_id and total.time <= pv_yes.time
  LEFT JOIN scroll on pv_yes.user_pseudo_id = scroll.user_pseudo_id and pv_yes.ga_session_id = scroll.ga_session_id and pv_yes.time <= scroll.time