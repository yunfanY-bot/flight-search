Our program works as intended.

For example:

## We input LAX as the departure airport and PVG as the destination airport

it will ouput

Airport ID: 3484

name: Los Angeles International Airport

country: United States

City: Los Angeles

iata: LAX

icao: KLAX

Lat: 33.9425

Lon: -118.408

      |
      |
      | 10415.3 KM
      |
      |
      
Airport ID: 3406

name: Shanghai Pudong International Airport

country: China

City: Shanghai

iata: PVG

icao: ZSPD

Lat: 31.1434

Lon: 121.805

Total Distance is:  

10415.3 KM 


## BUT, if we input lax instead of LAX, it will output 

Wrong airport code!

## Also, we identify some "ghost" airports. The airports do exist, but there are no flight information about them, which makes them ghosts.

Input AAA as the departure airport and PVG as the destination airport,

it will output

One of them is a Ghost Airport!

(Airport exist but route information not found)

## What's more, if we set the same departure and destination airport, it will output

Invalid input!

## Funny Discovery

if we set the departure airport as PVG (Shanghai) and the destination airport as HGH (Hangzhou), 


it shows the route is PVG -> FOC (Fuzhou) -> HGH, which is redundant. In fact, Shanghai is too close to Hangzhou, and it is supposed to travel by train instead of by flight. In reality, no one would actually take the flight to Hangzhou from Shanghai:)

