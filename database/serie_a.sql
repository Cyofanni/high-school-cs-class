//from mysql shell, run the command: source serie_a.sql

CREATE DATABASE IF NOT EXISTS serie_a_db;

USE serie_a_db;

CREATE TABLE teams(
      id INT AUTO_INCREMENT,
      name VARCHAR(20) NOT NULL,
      date_est DATE,
      revenue decimal(6, 2) NOT NULL,
      new_promoted BOOL,
      colour ENUM('red', 'white', 'green', 'black', 'yellow', 'blue'),
      PRIMARY KEY(id)
);

ALTER TABLE teams MODIFY new_promoted BOOL NOT NULL;
ALTER TABLE teams MODIFY new_promoted ENUM('red', 'white', 'green', 'black', 'yellow', 'blue') NOT NULL;

CREATE TABLE players(
      id INT AUTO_INCREMENT,
      name VARCHAR(20) NOT NULL,
      surname VARCHAR(20) NOT NULL,
      birthdate DATE NOT NULL,
      salary DECIMAL(6, 2),
      country VARCHAR(20) NOT NULL,
      team INT,
      PRIMARY KEY(id),
      FOREIGN KEY(team) REFERENCES teams(id)
);
