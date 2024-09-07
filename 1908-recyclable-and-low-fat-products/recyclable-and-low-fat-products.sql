# Write your MySQL query statement below
SELECT product_id
FROM Products
WHERE (Products.low_fats LIKE "Y" AND Products.recyclable LIKE "Y");