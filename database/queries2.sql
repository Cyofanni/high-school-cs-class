/*describe students;
+----------------------+--------------+------+-----+---------+----------------+
| Field                | Type         | Null | Key | Default | Extra          |
+----------------------+--------------+------+-----+---------+----------------+
| id                   | int          | NO   | PRI | NULL    | auto_increment |
| name                 | varchar(20)  | YES  |     | NULL    |                |
| surname              | varchar(20)  | YES  |     | NULL    |                |
| class                | varchar(4)   | YES  | MUL | NULL    |                |
| residenceCity        | varchar(20)  | YES  |     | NULL    |                |
| avgMark              | decimal(4,2) | YES  |     | NULL    |                |
| annualFamiliarIncome | decimal(6,2) | YES  |     | NULL    |                |
| birthday             | date         | YES  |     | NULL    |                |
+----------------------+--------------+------+-----+---------+----------------+
*/

/*extract the count of records for each residenceCity*/
SELECT residenceCity, COUNT(*) AS num_of_students
FROM students
GROUP BY residenceCity;

/*extract the count of records for each class,
  when class is defined*/
SELECT class, COUNT(*) AS num_of_students
FROM students
WHERE class IS NOT NULL
GROUP BY class;

/*extract the count of records for each residenceCity;
  count must be > 2*/
SELECT residenceCity, COUNT(*) AS num_students
FROM students
GROUP BY residenceCity
HAVING num_students > 2;

/*extract this:
+-------------+----------------+-----------+--------------+----------------+
| player_name | player_surname | team_name | coach_name   | coache_surname |
+-------------+----------------+-----------+--------------+----------------+*/
SELECT players.name AS player_name, players.surname AS player_surname, teams.name AS team_name,
coaches.name AS coach_name, coaches.surname AS coache_surname
FROM players
JOIN teams
ON players.team = teams.id
JOIN coaches
ON coaches.team = teams.id;
