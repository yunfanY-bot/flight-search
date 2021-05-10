Our program works as intended.

For example:

## We input LAX as the departure airport and PVG as the destination airport

it shows that

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



## BUT, if we input lax instead of LAX, it will show 

No such airport!


## Funny Discovery

if we set the departure airport as PVG (Shanghai) and the destination airport as HGH (Hangzhou), 


it shows the route is PVG -> FOC (Fuzhou) -> HGH, which is redundant. In fact, Shanghai is too close to Hangzhou, and it is supposed to travel by train instead of by flight. In reality, no one would actually take the flight to Hangzhou from Shanghai:)



