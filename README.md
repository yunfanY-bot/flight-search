Optimal Travel Solver



## How does our project work?
Our project uses the data from Open Flights to find the optimal route between two airports. We weighted the route basically by distance. We set latitude and longitude to be the factors that affect the distance. Data struture Graph is used. We use Dijkstra's algorithm to search the best route in our map.


## Coding Style

C++ 


## How to use our program?

To download our program, please copy and paste the following line to your terminal:

    git clone https://github-dev.cs.illinois.edu/cs225-sp21/yunfany3-yixiang9-jinruih2-jiayuz6.git cs225finalproject
    
Once you finish downloading and setups, go to the directory of our project:
    
    cd cs225finalproject

(If make command does not succeed, you may need to remove the .objs file from the directory before running our program)

    make
    ./final
    
It may takes 20s for our program to build graph, then you will see "Please type departure airport IATA code (input q to quit)" in the terminal:

Open airports.dat.txt, enter IATA codes (3-letter codes) of desired airports (eg. Los Angeles->LAX, remember, this has to be CAPITALIZED, lax will not be a valid code). Invalid airports will be filtered by our program.

Then enter the destination airport IATA code, and wait for a few seconds you will see the best route we calculate for you:)


## Sample output


![image](https://github-dev.cs.illinois.edu/cs225-sp21/yunfany3-yixiang9-jinruih2-jiayuz6/blob/master/sampleoutput.png)






## Here is the link to our presentation!

https://youtu.be/YW-F28cqZoQ

# Hope you enjoy our project!

