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
    vector<Vertex> trees;
    ifstream input("input.txt");
    string s;
    while(getline(input, s)){
        stringstream p(s);
        Vertex tree;
        p>>tree.Coordinate.x>>tree.Coordinate.y>>tree.Weight;
        trees.push_back(tree);
    }
    const int N = 3;
    const int M = 20;
//    Vertex grid[N][M];
//    for(int i = 0 ; i < N; i++){
//        for(int j = 0 ;j <M; j++){
//            grid[i][j].Weight = rand() % 100;
//        }
//    }

    Graph g = {N,M};
    Coord startPoint = {1, 0};
    Coord goalPoint = {1, 19};
    auto path = g.find_path_Dijkstra(startPoint, goalPoint);
    for (auto path_coord : path)
    {
        std::cout << path_coord.x << " "<<path_coord.y<<endl;
    }
}
