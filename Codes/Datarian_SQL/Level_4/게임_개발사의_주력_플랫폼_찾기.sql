with sales_data as (
  SELECT 
    companies.name as developer,
    platforms.name as platform, 
    sum(sales_eu + sales_jp + sales_na + sales_other) as sales
  FROM companies
    LEFT JOIN games on companies.company_id = games.developer_id
    LEFT JOIN platforms on games.platform_id = platforms.platform_id
  GROUP BY developer, platform
  HAVING platform IS NOT NULL and sales IS NOT NULL
), ranks as (
  select *, rank() over(PARTITION BY developer ORDER BY sales DESC) as sales_rank
  from sales_data
)
select developer, platform, sales
from ranks
where sales_rank = 1