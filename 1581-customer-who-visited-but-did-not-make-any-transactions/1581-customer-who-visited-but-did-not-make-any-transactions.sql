SELECT v.customer_id , COUNT(visit_id) AS 'count_no_trans' FROM Visits v
WHERE visit_id NOT IN (
        SELECT visit_id FROM Transactions
    )
GROUP BY customer_id;