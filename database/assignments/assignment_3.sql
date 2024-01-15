DROP TABLE IF EXISTS discoveries;
DROP TABLE IF EXISTS scientists;

CREATE TABLE scientists(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  surname VARCHAR(20) NOT NULL,
  birthdate DATE NOT NULL,
  deathdate DATE NOT NULL,
  field VARCHAR(20) NOT NULL,
  country VARCHAR(20) NOT NULL,
  received_nobel_prize BOOLEAN NOT NULL,
  PRIMARY KEY(id)
);

CREATE TABLE discoveries(
  id INT AUTO_INCREMENT,
  name VARCHAR(20) NOT NULL,
  field VARCHAR(20) NOT NULL,
  year INT NOT NULL,
  id_scientist INT,
  PRIMARY KEY(id),
  FOREIGN KEY(id_scientist) REFERENCES scientists(id)
);

INSERT INTO scientists(name, surname,
            birthdate, deathdate,
            field, country, received_nobel_prize)
VALUES('Rita', 'Levi-Montalcini', '1909-04-22', '2012-12-30', 'physiology', 'Italy', 1),
      ('Isaac', 'Newton', '1642-12-25', '1727-03-30', 'physics', 'England', 0);

INSERT INTO discoveries(name, field,
            year, id_scientist)
VALUES('Nerve growth factor', 'genetics', 1956, 1),
      ('Classical mechanics', 'physics', 1676, 2),
      ('Gravitation', 'physics', 1683, 2);

SELECT
scientists.name AS scientist_name,
scientists.surname AS scientist_surname,
YEAR(birthdate) AS birthyear,
discoveries.name AS discovery,
discoveries.year AS discovery_year
FROM
scientists
JOIN
discoveries
ON scientists.id = id_scientist;



