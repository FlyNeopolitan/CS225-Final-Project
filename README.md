
![](https://img.shields.io/badge/release-v1.00-blue)
![](https://img.shields.io/badge/build-passing-brightgreen?style=flat&logo=visual-studio-code)
![](https://img.shields.io/badge/Zoom-Chat!-red?style=flat-square&logo=zoom)

## What is our project doing?

This project aims to implement a template directed graph in the form of adjacency list, and import data from open flights as a sample. With several graph algorithms like Dijkstra and betweenness centrality, this project may compute some useful information based on the data.  

## Introduction to data sample

We use airports data and routes data to build the graph: the vertex represents the airport; the edge represents route, and weight of the edge represents distance between two airports. 

For example, if there is a route from airport A to airport B, insert an edge from A to B with weight equals distance between airport A and B.  

Notice that the distance is a relative distance computed by latitude and longtitude!

## How to build and run executable

**1. Get project:**

```bash
git clone 
```

**2. Compile and link:**

```bash
make (make test)
```

**3. Run:** 

```bash
./main (./test)
```

**4. Other data** 

Currently the executable uses small sample data (Around 10 airports and 20 routes). If you want to use other data set, you could change main method in main.cpp easily. (Warning: If you use the complete data set, with around 14000 airports and 67000 routes, it will take a long time, about ten minutes, to compute betweenness centrality.)

## Data Source
[Open flights](<https://openflights.org/data.html>)
* [Airports data](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)
* [Routes data](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## Directory Structure
```bash
├── contract
│   ├── CONTRACT_chengji5.pdf
│   ├── CONTRACT_jingz15.pdf
│   ├── CONTRACT_jinzhec2.pdf
│   └── CONTRACT_yunzew2.pdf
├── data
│   ├── airports.txt
│   ├── routes.txt
│   ├── sample_airports.txt
│   └── sample_routes.txt
├── graph
│   ├── BFStraversal.h
│   ├── DFStraversal.h
│   ├── edge.h
│   ├── graph.h
│   ├── graph.hpp
│   └── graphIterator.h
├── main.cpp
├── Makefile
├── readFromFile.cpp
├── readFromFile.hpp
├── README.md
├── tests
│   ├── catch2
│   │   └── catch.hpp
│   └── test.cpp
└── written_report
    ├── cs225_final_report.pdf
    ├── DEVELOPMENT.md
    └── GOALS.md
```
