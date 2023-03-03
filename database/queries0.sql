INSERT INTO students(name, surname, class) VALUES ('john', 'white', '4AAA');

CREATE TABLE classes(name VARCHAR(4), major VARCHAR(20), location VARCHAR(20), PRIMARY KEY(name));

INSERT INTO classes(name, major, location) VALUES ('2AA', 'humanities', 'viale X1');

CREATE TABLE students(id INT AUTO_INCREMENT,
                      name VARCHAR(20),
                      surname VARCHAR(20),
                      class VARCHAR(4),
                      PRIMARY KEY(id),
                      FOREIGN KEY(class) REFERENCES classes(name));

SELECT * FROM students CROSS JOIN classes;

SELECT * FROM students
         JOIN
         classes
         ON students.class = classes.name;

SELECT id, students.name, classes.name as className, major, location
       FROM students
       JOIN classes
       ON students.class = classes.name;

ALTER TABLE students ADD COLUMN residenceCity VARCHAR(20);

SELECT COUNT(*), residenceCity FROM students GROUP BY residenceCity;

ALTER TABLE students ADD COLUMN avgMark DECIMAL(3, 2);

SELECT * FROM students
              WHERE avgMark >
	      (SELECT avg(avgMark)
	       FROM
               students);

SELECT * FROM students
              JOIN
	      classes
	      ON
	      students.class = classes.name
	      WHERE classes.major = 'humanities';

SELECT * FROM students UNION SELECT * FROM students_1;

SELECT name, surname FROM students WHERE annual_familiar_income =
       (SELECT MAX(annual_familiar_income)
        FROM students);

SELECT * FROM students_1 WHERE name NOT IN
       (SELECT name
        FROM students);
