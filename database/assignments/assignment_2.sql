/*
  "a person has two parents..."
  create a relational database that describes this miniworld.
*/

DROP DATABASE IF EXISTS assignment_2;
CREATE DATABASE assignment_2;
USE assignment_2;

CREATE TABLE people(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  surname VARCHAR(20) NOT NULL,
  birthdate DATE NOT NULL,
  gender CHAR(1) NOT NULL,
  parent_1_id INT,
  parent_2_id INT,
  PRIMARY KEY(id),
  FOREIGN KEY(parent_1_id) REFERENCES people(id),
  FOREIGN KEY(parent_2_id) REFERENCES people(id)
);

INSERT INTO people(name, surname, birthdate, gender)
VALUES('silvia', 'rossi', '1925-04-12', 'F'),
      ('luigi', 'bianchi', '1930-04-12', 'M'),
      ('lucia', 'rossini', '1936-05-06', 'F'),
      ('angelo', 'verdi', '1934-11-01', 'M');

INSERT INTO people(name, surname, birthdate, gender, parent_1_id, parent_2_id)
VALUES('maria', 'bianchi', '1960-04-12', 'F', 1, 2),
      ('giorgio', 'verdi', '1965-06-03', 'M', 3, 4);


INSERT INTO people(name, surname, birthdate, gender, parent_1_id, parent_2_id)
VALUES('giovanni', 'verdi', '1988-07-03', 'M', 5, 6);

/*1. 
write a query that produces this output:
+-------------+----------------+---------------+------------------+
| person_name | person_surname | parent_1_name | parent_1_surname |
+-------------+----------------+---------------+------------------+
| maria       | bianchi        | silvia        | rossi            |
| giorgio     | verdi          | lucia         | rossini          |
| giovanni    | verdi          | maria         | bianchi          |
+-------------+----------------+---------------+------------------+
*/
SELECT
p1.name AS person_name,
p1.surname AS person_surname,
p2.name AS parent_1_name,
p2.surname AS parent_1_surname
FROM
people AS p1
JOIN
people AS p2
ON p1.parent_1_id = p2.id;

/*2. 
write a query that produces this output:
+-------------+----------------+---------------+------------------+---------------+------------------+
| person_name | person_surname | parent_1_name | parent_1_surname | parent_2_name | parent_2_surname |
+-------------+----------------+---------------+------------------+---------------+------------------+
| maria       | bianchi        | silvia        | rossi            | luigi         | bianchi          |
| giorgio     | verdi          | lucia         | rossini          | angelo        | verdi            |
| giovanni    | verdi          | maria         | bianchi          | giorgio       | verdi            |
+-------------+----------------+---------------+------------------+---------------+------------------+
*/
SELECT
p1.name AS person_name,
p1.surname AS person_surname,
p2.name AS parent_1_name,
p2.surname AS parent_1_surname,
p3.name AS parent_2_name,
p3.surname AS parent_2_surname
FROM
people AS p1
JOIN
people AS p2
ON p1.parent_1_id = p2.id
JOIN
people AS p3
ON p1.parent_2_id = p3.id;

/*3. 
write a query that produces this output:
+-------------+----------------+---------------+------------------+--------------------+---------------+------------------+--------------------+
| person_name | person_surname | parent_1_name | parent_1_surname | parent_1_birthdate | parent_2_name | parent_2_surname | parent_2_birthdate |
+-------------+----------------+---------------+------------------+--------------------+---------------+------------------+--------------------+
| maria       | bianchi        | silvia        | rossi            | 1925-04-12         | luigi         | bianchi          | 1930-04-12         |
+-------------+----------------+---------------+------------------+--------------------+---------------+------------------+--------------------+
the output must include only people who have at least one parent born before January 1st, 1930.
*/
SELECT
p1.name AS person_name,
p1.surname AS person_surname,
p2.name AS parent_1_name,
p2.surname AS parent_1_surname,
p2.birthdate AS parent_1_birthdate,
p3.name AS parent_2_name,
p3.surname AS parent_2_surname,
p3.birthdate AS parent_2_birthdate
FROM
people AS p1
JOIN
people AS p2
ON p1.parent_1_id = p2.id
JOIN
people AS p3
ON p1.parent_2_id = p3.id
WHERE p2.birthdate < '1930-01-01' OR p3.birthdate < '1930-01-01';
