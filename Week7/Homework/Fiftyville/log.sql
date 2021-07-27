-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Investiage crime scence report on the day that theft took place, i.e. July 28, 2020 
select id, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year=2020 AND street = 'Chamberlin Street';
--Takeaways from crime scene report:
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
select transcript FROM interviews WHERE day = 28 AND month = 7 AND year=2020;
--Takeaways from Interviews:
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--Sometime within ten minutes of the theft get into a car in the courthouse parking lot and drive away -> security footage from the courthouse parking lot
--leaving the courthouse -> CALL: flight to departure country purchased
--called someone who talked to them for less than a minute.
--earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--Find all car activities in courtouse within 10 minutres aroud 10:15 am, in which the activity is exit (not entrance)
SELECT year, month, day, hour,minute, activity, license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND year=2020 AND minute >= 10 AND minute <= 20 AND activity = 'exit' ORDER BY minute;
-- Find people with designated license plates
SELECT name FROM people WHERE license_plate IN ('NRYN856', 'NRYN856', 'D965M59', 'HW0488P', '13FNH73' , '5P2BI95', '94MV71O', 'V47T75I', '94KL13X', '6P58WS2', 'NAW9653', 'R3G7486', '4328GD8', 'G412CB7') ORDER BY name;
-- List of all Calls on that day which have less than a minute duration, represented by caller and receiver's numbers respectively
SELECT id, caller, receiver, duration FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration <= 60;
--Find people with designated phone numbers as callers
SELECT name FROM people WHERE phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(609) 555-5876', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650') ORDER BY name;
-- List of transactions on that day that took place on Fifer Street, restricted to only withdrawal type of transaction
SELECT account_number, amount FROM atm_transactions WHERE day = 28 AND month = 7 AND year=2020 AND atm_location = 'Fifer Street'AND transaction_type = 'withdraw';
-- Find people with designated bank account numbers
SELECT person_id FROM bank_accounts WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);
--Intersect bank accounts and telephone numbers:
SELECT name FROM people WHERE id IN (686048, 514354, 458378, 395717, 396669, 467400, 449774, 438727) AND phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(609) 555-5876', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650') ORDER BY name;
-- Ernest was the only intersection!
-- Discover Ernest's profile in people table:
SELECT name, phone_number, license_plate FROM people WHERE name = 'Ernest';
-- Ernest|(367) 555-5533|94KL13X
-- Find receiver's profile:
-- first find his phone number:
SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND day = 28 AND month = 7 AND year=2020 AND duration <= 60;
-- (375) 555-8161
SELECT name FROM people WHERE phone_number = '(375) 555-8161';
-- name = Berthold
-- Since in interview it is mentioned that Berthold purchased the earliest flight tomorrow:
-- Find Fiftyville town id in airport:
SELECT id, abbreviation, full_name, city FROM airports WHERE city = 'Fiftyville' 
-- 8|CSF|Fiftyville Regional Airport|Fiftyville
SELECT destination_airport_id, hour FROM flights WHERE day = 29 AND month = 7 AND year=2020 AND origin_airport_id = 8 ORDER BY hour; 
-- 4|8 -> Earliest flight is on 8 o'clock and to id 4
-- Find origin and destination of flight:
SELECT id, abbreviation, full_name, city FROM airports WHERE id = 4;
-- 4|LHR|Heathrow Airport|London
