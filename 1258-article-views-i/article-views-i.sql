# Write your MySQL query statement below
SELECT DISTINCT(author_id) as id
From Views
Where author_id=viewer_id
ORDER BY author_id ASC;