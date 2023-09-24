#pragma once
#define SIZE 10
#include <vector>
#define VERYBIGINT 1000000000
class Graph
{
    public:

        Graph()
        {
            for(int i=0; i < SIZE; i++)
                for(int j=0; j < SIZE; j++)
                    _matrix[i][j] = 0;
            _vertexCount = 0;
        }

        void AddVertex(int vnumber);
        void RemoveVertex(int vnumber);
        void AddEdge(int v1, int v2, int weight);
        void DeleteEdge(int v1, int v2);
        void ShowMatrix();
        bool EdgeExists(int v1, int v2);
        bool VertexExists(int vnumber);
        void DepthInner(int current, bool visited[]);
        void Depth(int start);
        void Width(int start);
        void findMinDistanceDecstr(int fromVert, int toVert);
        int findPathCount(int from, int to); 
        void depthInnerPlus(int from, bool visited[], int to, int& count, std::vector<int>& path);

    private:
        int _matrix[SIZE][SIZE];
        int _vertices[SIZE];
        int _vertexCount;
        

};