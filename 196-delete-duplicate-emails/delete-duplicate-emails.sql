DELETE
FROM Person
WHERE (id, email) NOT IN (
    SELECT MIN(id), email
    FROM (
        SELECT *
        FROM Person
    ) p
    GROUP BY email
)