SELECT title FROM MOVIES WHERE year=2008;
SELECT birth FROM people WHERE name = 'Emma Stone';
SELECT title FROM movies WHERE year >= 2018 ORDER BY title
SELECT COUNT(title) FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = 10.0);
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;
SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year=2012);
SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE movies.id IN (SELECT id FROM movies WHERE year = '2010') ORDER BY ratings.rating DESC, movies.title ASC;
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN (SELECT id FROM movies WHERE title = 'Toy Story'));
SELECT name FROM people WHERE id IN (SELECT DISTINCT(person_id) FROM stars WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004)) ORDER BY birth;
SELECT name FROM people WHERE id IN (SELECT DISTINCT(person_id) FROM directors WHERE movie_id IN (SELECT movie_id FROM ratings WHERE rating >= 9.0));
SELECT movies.title FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE movies.id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = 'Chadwick Boseman')) ORDER BY rating DESC LIMIT 5;
SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name IN ('Johnny Depp', 'Helena Bonham Carter')) GROUP BY movie_id HAVING COUNT(DISTINCT person_id) = 2);
SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958))) AND name != 'Kevin Bacon';
