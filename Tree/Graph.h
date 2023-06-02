//
//  Graph.h
//  Tree
//
//  Created by Maria on 31.05.2023.
//

#ifndef Graph_h
#define Graph_h
#include "Structures.h"
#include <vector>
#include <math.h>
#include <map>

class Graph{
    public:
        Graph(unsigned int n,  unsigned int m, int move_step, unsigned int road_len);
        std::vector<Coord> find_path_Dijkstra(Coord startPoint, Coord goalPoint);
    private:
        // Количество вершин по оси Ox
        unsigned int N;
        // Количество вершин по оси Oy
        unsigned int M;
        int Move_Step;
        Coord change_coord = {0,0};
        // Набор всех клеток
        Vertex **Vertices;
        void Create_Grid();
        void Fill_Grid();
        std::vector<Coord> GetAllAdjacentVertices(Coord vertex);
        std::vector<Coord> GetValidNeighbors(Coord current);
        std::vector<Coord> ConvertGraphToPath(Coord startPoint, Coord goalPoint);
        
   
};

#endif /* Graph_h */
