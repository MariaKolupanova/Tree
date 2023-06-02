//
//  Structures.h
//  Tree
//
//  Created by Maria on 31.05.2023.
//

#ifndef Structures_h
#define Structures_h
#include <algorithm>
#include <iostream>

const auto INF = std::numeric_limits<int>::max();

struct Coord
{
    int x,y;
    bool operator == (const Coord& c) {
           return x == c.x && y == c.y;
    }
};


struct Vertex
{
    Coord CameFrom = {INF,INF};
    double Weight = INF;
    bool IsVisited = false;
    double Label = INF;
};

#endif /* Structures_h */
