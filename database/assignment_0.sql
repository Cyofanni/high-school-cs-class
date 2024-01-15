DROP DATABASE IF EXISTS assignment_0;
CREATE DATABASE assignment_0;
USE assignment_0;
DROP TABLE IF EXISTS teacher_class_conn;
DROP TABLE IF EXISTS teachers;
DROP TABLE IF EXISTS classes;

CREATE TABLE teachers(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  surname VARCHAR(20) NOT NULL,
  PRIMARY KEY(id)
);

CREATE TABLE classes(
  id INT AUTO_INCREMENT,
  name VARCHAR(4) NOT NULL,
  major VARCHAR(20) NOT NULL,
  PRIMARY KEY(id)
);

INSERT INTO teachers(name, surname)
VALUES('nicoletta', 'bianchi'),
      ('elia', 'rossi'),
      ('stefania', 'verdi');

INSERT INTO classes(name, major)
VALUES('4BSA', 'science'),
      ('4ASA', 'science'),
      ('1AC', 'humanities');

CREATE TABLE teacher_class_conn(
  teacher_id INT,
  class_id INT,
  PRIMARY KEY(teacher_id, class_id),
  FOREIGN KEY(teacher_id) REFERENCES teachers(id),
  FOREIGN KEY(class_id) REFERENCES classes(id)
);

INSERT INTO teacher_class_conn(teacher_id, class_id)
VALUES(1, 3),
      (1, 2),
      (2, 1);

/*write a query that produces the following output:
   teacher_name, teacher_surname, class_name
*/
SELECT
teachers.id AS teacher_id,
teachers.name AS teacher_name,
teachers.surname AS teacher_surname,
classes.name AS class
FROM
teacher_class_conn
JOIN
teachers
ON teacher_class_conn.teacher_id = teachers.id
JOIN
classes
ON
teacher_class_conn.class_id = classes.id;
