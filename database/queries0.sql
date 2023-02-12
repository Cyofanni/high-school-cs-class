create table students(id INT AUTO_INCREMENT, name VARCHAR(20), surname VARCHAR(20), class VARCHAR(4), PRIMARY KEY(id));

insert into students(name, surname, class) values ('john', 'white', '4AAA');

create table classes(name VARCHAR(4), major VARCHAR(20), location VARCHAR(20), primary key(name));

insert into classes(name, major, location) values ('2AA', 'humanities', 'viale X1');

create table students(id INT AUTO_INCREMENT, name VARCHAR(20), surname VARCHAR(20), class VARCHAR(4), PRIMARY KEY(id), FOREIGN KEY(class) REFERENCES
classes(name));


