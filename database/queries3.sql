/*create a self-referential table*/
CREATE TABLE parents_children(
    id INT AUTO_INCREMENT,
    name VARCHAR(20),
    surname VARCHAR(20),
    child_of INT,
    PRIMARY KEY(id),
    FOREIGN KEY(child_of) REFERENCES parents_children(id)
);
/*examples of records
+----+----------+---------+----------+
| id | name     | surname | child_of |
+----+----------+---------+----------+
|  1 | mario    | rossi   |     NULL |
|  2 | davide   | bianchi |     NULL |
|  3 | giorgio  | bianchi |        2 |
|  5 | giovanni | rossi   |        1 |
+----+----------+---------+----------+
*/
/*extract this:
+------------+---------------+-------------+----------------+
| child_name | child_surname | parent_name | parent_surname |
+------------+---------------+-------------+----------------+
| giorgio    | bianchi       | davide      | bianchi        |
| giovanni   | rossi         | mario       | rossi          |
+------------+---------------+-------------+----------------+
*/
SELECT p1.name AS child_name, p1.surname AS child_surname, p2.name AS parent_name, p2.surname AS parent_surname
FROM people_parent AS p1
JOIN people_parent
AS p2
ON p1.child_of = p2.id;
