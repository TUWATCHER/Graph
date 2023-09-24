#include "Graph.h"
#include <iostream>
#include <vector>
void Graph::AddVertex(int vnumber)
{
    _vertices[_vertexCount++] = vnumber;
}

void Graph::RemoveVertex(int vnumber)
{
    for (int i = 0; i < _vertexCount; i++)
    {
        
        if (vnumber == _vertices[i])
        {
            for (int j = i; j < _vertexCount; j++)
            {
                _vertices[j] = _vertices[j + 1];
                _vertices[j + 1] = 0;
            }
            _vertexCount--;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        DeleteEdge(vnumber, i);
        DeleteEdge(i, vnumber);
    }
    
    
}

void Graph::AddEdge(int v1, int v2, int weight)
{
    _matrix[v1][v2] = weight;
    _matrix[v2][v1] = weight;
}

void Graph::DeleteEdge(int v1, int v2)
{
    _matrix[v1][v2] = 0;
    _matrix[v2][v1] = 0;
}

void Graph::ShowMatrix()
{
    for (int i = 0; i < SIZE; i++)
    {    
        for(int j = 0; j < SIZE; j++)
        {
            std::cout << _matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

bool Graph::EdgeExists(int v1, int v2)
{
    return _matrix[v1][v2] != 0;
}

bool Graph::VertexExists(int vnumber)
{
    for (int i = 0; i < _vertexCount; i++)
    {
        if (_vertices[i] == vnumber)
            return true;
    }
    return false;
}

void Graph::DepthInner(int current, bool visited[])
{
    std::cout << "V: " << current << " -> ";
    visited[current] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (EdgeExists(current, i) && !visited[i])
        {
            DepthInner(i, visited);
        }
    }
}

void Graph::Depth(int start)
{
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    DepthInner(start, visited);

    std::cout << std::endl;
}

void Graph::Width(int start)
{
    int queue_to_visit[SIZE]; 
   int queueCount = 0;

   bool visited[SIZE]; 
   for(int i =0; i<SIZE; i++) 
       visited[i] = false;
   
   queue_to_visit[queueCount++] = start; 
   while(queueCount > 0)
   {
       
       int current = queue_to_visit[0];
       queueCount--;
       for(int i=0; i<queueCount; i++)
       {
           queue_to_visit[i] = queue_to_visit[i+1];
       }
       visited[current] = true;
       std::cout << "v" << current << " -> ";
       
       for(int i = 0; i<SIZE; i++)
       {
           bool alreadyAdded = false;
           for(int j=0; j<queueCount; j++)
              if(queue_to_visit[j] == i )
              {
                 alreadyAdded = true;
                 break;
              }
           if(!alreadyAdded && EdgeExists(current,i) && !visited[i])
               queue_to_visit[queueCount++] = i;
       }
   }
   std::cout << std::endl;
}

void Graph::findMinDistanceDecstr(int fromVert, int toVert)
{
    int minDist = 0;
    int distances[SIZE]; // массив меток
    for(int i=0; i<SIZE; i++) // инициализация меток
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;
    
    bool passed[SIZE]; // признак, что вершина окрашена
    for(int i=0; i<SIZE; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while(min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую
        
        for(int i=0; i< SIZE; i++)
        {
            // для смежных ребер пересчитываем метки
            if(EdgeExists(currentVertexNum,i)
               && distances[currentVertexNum] + _matrix[currentVertexNum][i] < distances[i])
                    distances[i] = 
                      distances[currentVertexNum] + _matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for(int i = 0; i< SIZE; i++)
        {
            // выбираем новую текущую вершину
            if (VertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    
    for(int i=0; i<_vertexCount; i++) // вывод результата
    {
        std::cout << "V" << i << ": " << distances[_vertices[i]] << ", ";
    }

    std::cout << distances[toVert];
    std::cout << std::endl;
}

    void Graph::depthInnerPlus(int from, bool visited[], int to, int& count, std::vector<int>& path)
    {
        path.push_back(from);
        visited[from] = true; // помечаем как посещенную
        if (from == to)
        {
            for (const auto v : path)
            {
                std::cout << v << " -> ";
            }
                
            std::cout << std::endl;
            count++;
        }
        else
        {
            for (int i = 0; i < SIZE; i++) {
                if (EdgeExists(from, i) && !visited[i])
                {
                    depthInnerPlus(i, visited, to, count, path);
                    
                }
            }
        }
        path.pop_back();
        
        visited[from] = false;
    }

int Graph::findPathCount(int from, int to)
    {
        int count = 0;
        bool visited[SIZE]; // 
        for (int i = 0; i < SIZE; i++)
            visited[i] = false; 
        std::vector<int> path;
        path.push_back(from);
        visited[from] = true; 
        path.pop_back();
        visited[from] = false;
        std::cout << "Возможные пути к заданной вершине: " << '\n';
        depthInnerPlus(from, visited, to, count, path); // запуск алгоритма
        std::cout << "SIZE: " << path.size() << '\n';
        std::cout << "Число возможных путей к данной вершине равно  ";
        return count;
        std::cout << '\n';
    }



