Project Goals


##Dataset: Openflights

https://openflights.org/data.html

Using data structure graph

--Vertices->Airports

--Edges->available flight routes between two airports

To build the graph, we use Adjacency Matrix to store airport IDs and Route Distances and use a map to link id to airport objects.

##Shortest Path Algorithms:
Dijkstra’s algorithm
--We set longitude and latitude coordinates of airports to calculate the distance between two airports, and this is how we determine the weight of edges.
--We implement Dijkstra’s algorithm to get the shortest path between 2 airports based on the shortest distance we just calculated.

##Final Deliverable:
Given the departure and destination airports as inputs from the user, the program will output the connecting flights for the shortest total distance if the inputs and outputs are valid 3-letter IATA codes. If inputs are not valid, it will show “No such airport!”. To quit the program, simply type “q”.

##Timeline:
Week April 19-25, we finished parsing airports and routes from the file that the dataset provides. 
Week April 26-May 2, we finished building our graph by using adjacency matrix and mapping it to airports.
Week May 3-9, we finished Dijkstra’s algorithm to find the shortest path between two airports, and the whole project has been completed.
