# Write your MySQL query statement below
SELECT o.id from Weather o
JOIN Weather t ON DATEDIFF(o.recordDate, t.recordDate) = 1
WHERE o.temperature > t.temperature;