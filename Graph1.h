#pragma once

#define SIZE 10

class Graph 
{
    
    struct Edge 
    { 
        int vertexWhere; // в какую вершину ведет
        int weight; // вес ребра
        Edge() {}
        Edge(int vw, int w): vertexWhere(vw), weight(w) {}
    };
    
    struct Vertex
    {  
        int number; 
        Edge adj_vertexes[SIZE]; 
        int edgeCount;
    };

    public:

        Graph()
        {
           vertexCount = 0;
        }

    private:
        Vertex vertexes[SIZE];
        int vertexCount;
};
 