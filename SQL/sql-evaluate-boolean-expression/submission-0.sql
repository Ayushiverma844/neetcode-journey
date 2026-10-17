-- Write your query below
SELECT 
    e.left_operand , e.operator , e.right_operand,
    CASE
        WHEN e.operator = '>' AND l.value > r.value THEN 'true'
        WHEN e.operator = '<' AND l.value < r.value THEN 'true'
        WHEN e.operator = '=' AND l.value = r.value THEN 'true'
        ELSE 'false'
    END AS VALUE
FROM
expressions e
LEFT JOIN variables l ON e.left_operand = l.name 
LEFT JOIN variables r ON e.right_operand = r.name ;