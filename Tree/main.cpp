//
//  main.cpp
//  Tree
//
//  Created by Maria on 29.05.2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

int main()
{
//    vector<Vertex> trees;
//    ifstream input("input.txt");
//    string s;
//    while(getline(input, s)){
//        stringstream p(s);
//        Vertex tree;
//        p>>tree.Coordinate.x>>tree.Coordinate.y>>tree.Weight;
//        trees.push_back(tree);
//    }
    const int N = 10;
    const int M = 200;
    int move_step = 4;
    unsigned int road_len = 2;
//    Vertex grid[N][M];
//    for(int i = 0 ; i < N; i++){
//        for(int j = 0 ;j <M; j++){
//            grid[i][j].Weight = rand() % 100;
//        }
//    }

    Graph g = {N,M,move_step,road_len};
    // задать самую левую точку
    Coord startPoint = {2, 0};
    // задать самую левую точку
    Coord goalPoint = {7, 199};
    auto path = g.find_path_Dijkstra(startPoint, goalPoint);
    for (auto path_coord : path)
    {
        std::cout << path_coord.x << " "<<path_coord.y<<endl;
    }
}
