/*Ex 0*/

DROP DATABASE IF EXISTS hospital;
CREATE DATABASE hospital;
USE hospital;

CREATE TABLE doctors(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  surname VARCHAR(20) NOT NULL,
  birthdate DATE NOT NULL,
  PRIMARY KEY(id)
);

CREATE TABLE patients(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  surname VARCHAR(20) NOT NULL,
  birthdate DATE NOT NULL,
  country VARCHAR(20) NOT NULL,
  PRIMARY KEY(id)
);

CREATE TABLE d_p(
  doctor_id INT,
  patient_id INT,
  PRIMARY KEY(doctor_id, patient_id),
  FOREIGN KEY(doctor_id) REFERENCES doctors(id),
  FOREIGN KEY(patient_id) REFERENCES patients(id)
);

CREATE TABLE eu_countries(
  name VARCHAR(20),
  PRIMARY KEY(name)
);

INSERT INTO doctors(name, surname, birthdate)
VALUES('yyy', 'qweqwe', '1990-07-05'),
      ('antonio', 'aaa', '1976-12-10'),
      ('ernesto', 'b', '1961-10-10'),
      ('tonio', 'cartonio', '1963-05-01'),
      ('tonio', 'pinzimonio', '1991-05-01');

INSERT INTO patients(name, surname, birthdate, country)
VALUES('giovanni', 'mazzocchin', '1994-01-02', 'Italy'),
      ('gianni', 'qwerty', '1976-12-10', 'Italy'),
      ('ha', 'ab', '1973-10-10', 'Morocco'),
      ('a', 'b', '1983-05-01', 'China'),
      ('qwerty', 'baba', '1973-10-10', 'Italy'),
      ('sv', 'ko', '2001-01-06', 'Ukraine');

INSERT INTO d_p(doctor_id, patient_id)
VALUES(1, 1),
      (1, 2),
      (2, 4),
      (3, 1),
      (3, 3),
      (5, 6),
      (1, 6);

INSERT INTO eu_countries(name)
VALUES('Germany'),
      ('France'),
      ('Italy'),
      ('Spain'),
      ('Austria');

/*Ex 1*/
SELECT *
FROM doctors
WHERE id NOT IN
(
  SELECT doctor_id FROM d_p
);

/*Ex 2*/
SELECT
id AS doctor_id,
name AS doctor_name,
surname AS doctor_surname,
COUNT(*) AS num_patients
FROM
doctors
JOIN
d_p
ON doctors.id = d_p.doctor_id
GROUP BY id;

/*Ex 3*/
SELECT
doctors.name AS doctor_name,
doctors.surname AS doctor_surname,
patients.name AS patients_name,
patients.surname AS patients_surname
FROM
d_p
JOIN
doctors
ON d_p.doctor_id = doctors.id
JOIN
patients
ON d_p.patient_id = patients.id;

/*Ex 4*/
SELECT *
FROM patients
WHERE DATEDIFF(NOW(), birthdate) =
(
  SELECT MAX(DATEDIFF(NOW(), birthdate)) FROM patients
);

/*Ex 5*/
SELECT
name AS doctor_name,
surname AS doctor_surname,
COUNT(*) AS num_patients
FROM
doctors
JOIN
d_p
ON doctors.id = d_p.doctor_id
GROUP BY id
HAVING COUNT(*) >= 2;

/*Ex 6*/
SELECT
doctors.name AS doctor_name,
doctors.surname AS doctor_surname
FROM
d_p
JOIN
doctors
ON d_p.doctor_id = doctors.id
JOIN
patients
ON d_p.patient_id = patients.id
WHERE patients.birthdate > '2000-01-01';

/*Ex 7*/
SELECT *
FROM patients
WHERE country NOT IN
(
  SELECT name FROM eu_countries
);
