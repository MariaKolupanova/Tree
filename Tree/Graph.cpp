//
//  Graph.cpp
//  Tree
//
//  Created by Maria on 31.05.2023.
//

#include "Graph.h"
#include <stack>
Graph::Graph(const unsigned int n,const unsigned int m,int move_step,unsigned int road_len)
{
    N = n - road_len;
    M = m;
    Move_Step = move_step;
//    Road_Len = road_len;
    Create_Grid();
    Fill_Grid();
    
}
void Graph::Create_Grid()
{
    Vertices = new Vertex*[N];
    for (int i = 0; i < N; i++)
    {
        Vertices[i] = new Vertex[M];
    }
}
void Graph::Fill_Grid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Vertices[i][j].Weight = rand() % 100;
        }
    }
}
std::vector<Coord> Graph::GetValidNeighbors(Coord current)
{
    std::vector<Coord> elems = GetAllAdjacentVertices(current);
    return elems;
}
std::vector<Coord> Graph::ConvertGraphToPath(Coord startPoint, Coord goalPoint)
{
    std::vector<Coord> result;
    std::stack<Coord> tmp_path;
    Coord current_vertex = Vertices[goalPoint.x][goalPoint.y].CameFrom;
    Coord end ={INF,INF};
    while (current_vertex != end)
    {
        tmp_path.push(current_vertex);
        current_vertex = Vertices[current_vertex.x][current_vertex.y].CameFrom;
    }
    while (!tmp_path.empty())
    {
            result.push_back(tmp_path.top());
            tmp_path.pop();
    }
    result.push_back(goalPoint);
    return result;
}
std::vector<Coord> Graph::find_path_Dijkstra(Coord startPoint, Coord goalPoint)
{
    //сортировка по весу, результат - значение
    std::multimap<double, Coord> min_weigth_map;
    Vertices[startPoint.x][startPoint.y].Weight = 0;
    Vertices[startPoint.x][startPoint.y].Label = 0;
    min_weigth_map.insert({ 0,startPoint});
    while (!min_weigth_map.empty()  && !Vertices[goalPoint.x][goalPoint.y].IsVisited)
    {
        auto [current_weight, current_coord] = *(min_weigth_map.begin()); //минимальное значение
        min_weigth_map.erase(min_weigth_map.begin());
        if (Vertices[current_coord.x][current_coord.y].IsVisited)
        {
            continue;
        }
        Vertices[current_coord.x][current_coord.y].IsVisited = true;
        
        if(change_coord.y!= 0) change_coord.y += 1;
        if(Vertices[current_coord.x][current_coord.y].CameFrom.x != current_coord.x && (change_coord.y == 0)){
            change_coord.y += 1;
            change_coord.x = current_coord.x - Vertices[current_coord.x][current_coord.y].CameFrom.x;
        }
        if(change_coord.y > 5) change_coord = {0,0};
        std::vector<Coord> neighbors = GetValidNeighbors({current_coord});
        for (auto neighbor : neighbors)
        {
            if(neighbor.x < 0 || neighbor.y < 0 || neighbor.x >= N || neighbor.y >= M) continue;
            if (!Vertices[neighbor.x][neighbor.y].IsVisited)
            {
                double next_label = current_weight + Vertices[neighbor.x][neighbor.y].Weight;
                if (next_label < Vertices[neighbor.x][neighbor.y].Label )
                {
                    Vertices[neighbor.x][neighbor.y].Label = next_label;
                    Vertices[neighbor.x][neighbor.y].CameFrom = current_coord;
                    min_weigth_map.insert({next_label, neighbor});
                }
            }
        }
    }
    return ConvertGraphToPath(startPoint, goalPoint);
}

std::vector<Coord> Graph::GetAllAdjacentVertices(Coord v)
{
    std::vector<Coord> coord_movement;
    if(change_coord.y != 0 ){
        for(int i = 0; i <=1; i++){
                for(int j = 0; j <= Move_Step; j++ ){
                    if(change_coord.x > 0) coord_movement.push_back({v.x + j, v.y + i});
                    if(change_coord.x < 0) coord_movement.push_back({v.x - j, v.y + i});
                }
        }
    }
    else{
        for(int i = -1; i <=1; i++){
                for(int j = -Move_Step; j <= Move_Step; j++ ){
                    coord_movement.push_back({v.x + j, v.y + i});
            }
        }
    }


    return coord_movement;

}


