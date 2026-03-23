SELECT
  DATE_ADD(license_issue_date, INTERVAL 1 WEEK) as email_send_date,
  COUNT(DISTINCT license_number) as email_cnts
FROM
  seattle_pet_licenses
WHERE
license_issue_date >= '2016-10-01'
GROUP BY
  email_send_date