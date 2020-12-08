# Project Goals

## Summary of data set : OpenFlights

### Location :

https://openflights.org/data.html

### Database :

- We will use The OpenFlights Airports Database, routes Database to get the weight and edge. Each node represents an airport. 

```
Edge Weight = Relative Distance
```

- Attributes used for each database :

  - Airports Database : 

    https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat

    make use of Longitude, Latitude, AirportID to calculate distance. 

  - Routes Database : 

    https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat

    make use of Destination and Source Airport ID to calculate routes number. 

    

## Algorithms

### Covered :
- Traversal : BFS traversal 

- Shortest path : Dijkstra's Algorithm

### Uncovered/Complex :

- Importance of vertex : Betweenness centrality

### Others :
- Connectedness: check if two vertices are connected
- Advanced shortes path: get shortest path from one vertex to all others based on dynamic programming
