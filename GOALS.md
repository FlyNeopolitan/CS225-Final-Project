# Project Goals

## Summary of data set : OpenFlights

### Location :

https://openflights.org/data.html

### Database :

- We will use The OpenFlights Airports Database, routes Database to get the weight and edge. Each node represents an airport. 

```
Edge Weight= Distance
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

- Shortest path : Dijkstra's Algorithm

### Uncovered :

- Importance of vertex : Betweenness centrality
