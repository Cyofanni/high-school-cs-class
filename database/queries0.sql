INSERT INTO students(name, surname, class) VALUES ('john', 'white', '4AAA');

CREATE TABLE classes(name VARCHAR(4), major VARCHAR(20), location VARCHAR(20), PRIMARY KEY(name));

INSERT INTO classes(name, major, location) VALUES ('2AA', 'humanities', 'viale X1');

CREATE TABLE students(id INT AUTO_INCREMENT,
                      name VARCHAR(20),
                      surname VARCHAR(20),
                      class VARCHAR(4),
                      PRIMARY KEY(id),
                      FOREIGN KEY(class) REFERENCES classes(name));
