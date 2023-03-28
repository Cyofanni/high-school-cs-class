/*a teacher could teach in (0:n) classes;
  a class could have (0:n) teachers;

  teachers(id, name, surname);
  classes(id, name, major);
  ...
*/

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

/*...*/
