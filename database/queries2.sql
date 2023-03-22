/*table students;
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

/*extract distinct names from the table 'students'*/
SELECT DISTINCT name FROM students;

/*extract distinct pairs (name, surname) from the table 'students'*/
SELECT DISTINCT name, surname FROM students;

/*extract the count of different names from the table 'students'*/
SELECT COUNT(DISTINCT name) AS num_diff_names FROM students;



/*a teacher could teach in 0-n classes;
  a class could have 0-n teachers*/
/*
table classes:
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| name     | varchar(4)  | NO   | PRI | NULL    |       |
| major    | varchar(20) | YES  |     | NULL    |       |
| location | varchar(20) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+

table teachers:
teachers;
+---------+-------------+------+-----+---------+----------------+
| Field   | Type        | Null | Key | Default | Extra          |
+---------+-------------+------+-----+---------+----------------+
| id      | int         | NO   | PRI | NULL    | auto_increment |
| name    | varchar(20) | YES  |     | NULL    |                |
| surname | varchar(20) | YES  |     | NULL    |                |
+---------+-------------+------+-----+---------+----------------+
*/

CREATE TABLE teachers_classes (
    teacher_id INT,
    class VARCHAR(20),
    PRIMARY KEY(teacher_id, class),
    FOREIGN KEY(teacher_id) REFERENCES teachers(id),
    FOREIGN KEY(class) REFERENCES classes(name)
);

/*extract only teachers (name and surname, once per teacher) that teach in humanities*/
SELECT DISTINCT teachers.name, teachers.surname
FROM teachers
JOIN teachers_classes
ON teachers.id = teachers_classes.teacher_id
JOIN classes
ON teachers_classes.class = classes.name AND classes.major = 'humanities';
