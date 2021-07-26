SELECT name from SONGS;
SELECT name from SONGS ORDER BY tempo;
SELECT name from SONGS ORDER BY duration_ms DESC LIMIT 5;
SELECT name FROM songs WHERE (energy > 0.75 AND danceability > 0.75 AND valence > 0.75);
SELECT AVG(energy) FROM songs;
SELECT songs.name FROM songs JOIN artists ON artists.id = songs.artist_id WHERE artists.id IN (SELECT id FROM artists WHERE name ='Post Malone');
SELECT AVG(songs.energy) FROM songs JOIN artists ON artists.id = songs.artist_id WHERE artists.id IN (SELECT id FROM artists WHERE name ='Drake');
SELECT name FROM songs WHERE name LIKE '%feat%'
