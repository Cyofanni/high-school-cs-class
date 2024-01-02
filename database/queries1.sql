/*
composers
+----+------------------+---------------+------------+------------+------------+------------+---------+
| id | name             | surname       | birthday   | deathday   | birthplace | deathplace | country |
+----+------------------+---------------+------------+------------+------------+------------+---------+
|  1 | Wolfgang Amadeus | Mozart        | 1756-01-27 | 1791-12-05 | Salzburg   | Vienna     | Austria |
|  2 | Johann Sebastian | Bach          | 1685-03-21 | 1750-07-28 | Eisenach   | Leipzig    | Germany |
|  3 | Ludwig           | van Beethoven | 1770-12-17 | 1827-03-26 | Bonn       | Vienna     | Germany |
+----+------------------+---------------+------------+------------+------------+------------+---------+

favourite_composers
+--------------+
| surname      |
+--------------+
| bach         |
| chopin       |
| schumann     |
| shostakovich |
+--------------+
*/

/*
  extract the records (columns: all) from 'composers' such that the surname of the composers
  exists in the table 'favourite_composers'. Use a case insensitive match. 
*/
SELECT *
FROM composers
WHERE LOWER(surname)
IN
(SELECT surname
 FROM favourite_composers)

/*
works
works.composer is FOREIGN KEY to composers.id 
+----+---------------------+------------+----------+
| id | title               | issue_date | composer |
+----+---------------------+------------+----------+
|  1 | moonlight sonata    | 1802-05-03 |        3 |
|  2 | goldberg variations | 1740-05-03 |        2 |
|  5 | ninth symphony      | 1824-11-12 |        3 |
|  6 | chromatic fantasia  | 1720-12-13 |        2 |
|  7 | fifth symphony      | 1803-10-08 |        3 |
+----+---------------------+------------+----------+
*/
/*try to delete the record of 'Bach'*/
DELETE FROM composers WHERE surname = 'Bach';
/*ERROR 1451 (23000): Cannot delete or update a parent row: a foreign key constraint 
                    fails (`experiments`.`works`, CONSTRAINT `works_ibfk_1` FOREIGN KEY (`composer`) REFERENCES `composers` (`id`))
*/


/*see constraints*/
SHOW CREATE TABLE works;
/* CONSTRAINT `works_ibfk_1` FOREIGN KEY (`composer`) REFERENCES `composers` (`id`)
   //name of foreign key constraint is works_ibfk_1
drop existing constraint*/
ALTER TABLE works DROP CONSTRAINT works_ibfk_1;
/*create a new constraint*/
ALTER TABLE works ADD FOREIGN KEY(composer) REFERENCES composers(id) ON DELETE CASCADE;
ALTER TABLE works ADD FOREIGN KEY(composer) REFERENCES composers(id) ON DELETE RESTRICT;
ALTER TABLE works ADD FOREIGN KEY(composer) REFERENCES composers(id) ON DELETE CASCADE ON UPDATE CASCADE;
